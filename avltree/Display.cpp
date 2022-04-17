#include "Display.hpp"
//#define clearScreen() (std::cout << "\033c")
#define WAIT_TIME 300000    // 500000 = 0,5sek

Display::Display(Holder* holder) {
    printTree(holder);
}

// display preps, prints and self-destruct.
void Display::printTree(Holder* holder) {
    int depth = holder->getDepth(holder->getHead());
    int maxNumDigits = getDigits(holder->getMinMaxNum(holder->getHead(), true));

    for (int i = 0; i < depth+1; ++i) {
        displays.push_back("");
    }
    calcEmptySpaces(depth, maxNumDigits);
    recursiveDraw(depth, maxNumDigits, holder->getHead());

    usleep(WAIT_TIME);
    printDisplays();
    delete this;
}

// draw one node after another
void Display::recursiveDraw(int depth, int maxNumDigits, Node* node) {
    usleep(WAIT_TIME);
    printDisplays();
    if (depth < 0) return;
    int emptySpace = getEmptySpace(depth);
    displays.at(depth).append(emptySpace, ' ');
    displays.at(depth).append(drawNode(node, maxNumDigits));
    if (node->left == nullptr) {
        if (depth != 0) {
            recursiveDraw(depth-1, maxNumDigits);
        }
    } else {
        recursiveDraw(depth-1, maxNumDigits, node->left);
    }
    if (node->right == nullptr) {
        if (depth != 0) {
            recursiveDraw(depth-1, maxNumDigits);
        }
    } else {
        recursiveDraw(depth-1, maxNumDigits, node->right);
    }
    displays.at(depth).append(emptySpace, ' ');
    if (maxNumDigits == 1 || maxNumDigits == 3)
        displays.at(depth).append(" ");
}

// draw empty space, where nodes should've been
void Display::recursiveDraw(int depth, int maxNumDigits) {
    int emptySpace = getEmptySpace(depth);
    displays.at(depth).append(emptySpace, ' ');
    displays.at(depth).append(maxNumDigits+2, ' ');
    if (depth != 0) {
        recursiveDraw(depth-1, maxNumDigits);
        recursiveDraw(depth-1, maxNumDigits);

    }
    displays.at(depth).append(emptySpace, ' ');
}

// Node: (1) (2) ..
std::string Display::drawNode(Node* node, int maxNumDigits) {
    int digits = getDigits(node->num);
    if (maxNumDigits == digits)
        return "(" + std::to_string(node->num) + ")";
    if (maxNumDigits-1 == digits)
        return "( " + std::to_string(node->num) + ")";
    if (maxNumDigits-2 == digits)
        return "( " + std::to_string(node->num) + " )";
    if (maxNumDigits-3 == digits)
        return "(  " + std::to_string(node->num) + " )";
    if (maxNumDigits-4 == digits)
        return "(  " + std::to_string(node->num) + "  )";
    return " ";
}

// check how much digits the largest num in tree has
int Display::getDigits(int num) {
    if (num >= 1000) return 4;
    if (num >= 100) return 3;
    if (num >= 10) return 2;
    return 1;
}

// based on digit-amount of largest num in tree,
// decide which number-sequence to take for [empty space]-calculations
void Display::calcEmptySpaces(int depth, int maxNumDigits) {
    emptySpaces.clear();

    switch (maxNumDigits) {
        case 1:
            emptySpaces.push_back(0);
            for (int i = 0; i < depth; ++i) {
                emptySpaces.push_back(recursiveSingleSpace(0, i, 0));
            } break;
        case 2:
            emptySpaces.push_back(1);
            for (int i = 0; i < depth; ++i) {
                emptySpaces.push_back(recursiveDoubTripSpace(0, i, 0)+1);
            } break;
        case 3:
            emptySpaces.push_back(0);
            for (int i = 0; i < depth; ++i) {
                emptySpaces.push_back(recursiveDoubTripSpace(0, i, 0));
            } break;
        case 4:
            emptySpaces.push_back(1);
            for (int i = 0; i < depth; ++i) {
                emptySpaces.push_back(recursiveQuadSpace(0, i, 1));
            } break;
        default: break;
    }
}

// 3 formulas for number sequences to calculate spaces for given tree-depth
// n = (n*2)+2
int Display::recursiveSingleSpace(int depth, int maxDepth, int num) {
    if (depth < maxDepth) {
        return recursiveSingleSpace(depth+1, maxDepth, (num*2)+2);
    } else {
        return (num*2)+2;
    }
}

// n = n+3*2^d
int Display::recursiveDoubTripSpace(int depth, int maxDepth, int num) {
    if (depth < maxDepth) {
        return recursiveDoubTripSpace(depth+1, maxDepth, (num+3*(int)std::pow(2,depth)));
    } else {
        return (num+3*(int)std::pow(2,depth));
    }
}

// n = (2*n)+3
int Display::recursiveQuadSpace(int depth, int maxDepth, int num) {
    if (depth < maxDepth) {
        return recursiveQuadSpace(depth+1, maxDepth, ((2*num)+3));
    } else {
        return ((2*num)+3);
    }
}

// return number of spaces for given depth
int Display::getEmptySpace(int depth) {
    return emptySpaces.at(depth);
}

void Display::printDisplays() {
    std::cout << "\033c";
    for (int i = 0; i < displays.size(); ++i) {
        std::cout << displays.at(i) << "\n";
        std::cout << "-\n";
    }
}