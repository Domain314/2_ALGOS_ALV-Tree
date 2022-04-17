#include "Holder.hpp"

Holder::Holder() {
    this->head = nullptr;
}

void Holder::setHead(Node* newHead) {
    this->head = newHead;
}

Node* Holder::getHead() {
    return head;
}

// search for num in tree. if not found, return last node.
Node* Holder::searchTreeLast(Node* node, int num) {
    if (node->num == num) return node;
    else if (node->num < num) {
        if (node->right != nullptr) return searchTreeLast(node->right, num);
        else return node;
    } else if (node->num > num) {
        if (node->left != nullptr) return searchTreeLast(node->left, num);
        else return node;
    }
    //return node;
    return nullptr;
}

// return 0 or error code
int Holder::insertNode(int num) {
    if (head == nullptr) { setHead(new Node(num)); return 0; }
    else {
        Node* last = searchTreeLast(head, num);
        if (last->num == num) return 1;
        else if (last->num < num) { last->right = new Node(num); return 0; }
        else if (last->num > num) { last->left = new Node(num); return 0;}
        else return 2;
    }
    return 3;
}

// search for search-tree in base-tree
int Holder::searchNode(Node *base, Node* search) {
    if (base == nullptr) return 1;
    Node* res = searchTree(base, search->num);
    if (res == nullptr) return 1;
    else {
        if (res->num == search->num) {
            if (search->left != nullptr) {
                if (searchNode(res->left, search->left)) { return 1; }
            }
            if (search->right != nullptr) {
                if (searchNode(res->right, search->right)) { return 1; }
            }
        } else return 1;
    }
    return 0;
}

// search for num in tree, but return nullptr, if not found
Node* Holder::searchTree(Node *node, int num) {
    if (node->num == num) return node;
    else if (node->num < num) {
        if (node->right != nullptr) return searchTree(node->right, num);
        else return nullptr;
    } else if (node->num > num) {
        if (node->left != nullptr) return searchTree(node->left, num);
        else return nullptr;
    }
    return nullptr;
}

void Holder::searchSingle(Node *base, int num) {
    if (searchTree(base, num)) {
        std::cout << "\n" << num << " found ";
        printPath(base, num);
        std::cout << num;
    } else {
        std::cout << "\n" << num << " not found!";
    }
}

void Holder::printPath(Node *node, int num) {
    if (node->num == num) return;
    if (node->num > num) {
        std::cout << node->num << ", ";
        printPath(node->left, num);
    } else if (node->num < num) {
        std::cout << node->num << ", ";
        printPath(node->right, num);
    }
}

// lightweight depth calculation by Domain314
int Holder::getDepth(Node* node) {
    int depth = 0, maxDepth = 0;
    recursiveDive(++depth, maxDepth, node);
    return maxDepth;
}

// pass ints by reference to save some precious bits
void Holder::recursiveDive(int &depth, int &maxDepth, Node* node) {
    if (node == nullptr) return;
    if (depth > maxDepth) maxDepth = depth;
    recursiveDive(++depth, maxDepth, node->left);
    --depth;
    recursiveDive(++depth, maxDepth, node->right);
    --depth;
}

// get min or max num
int Holder::getMinMaxNum(Node* node, bool max) {
    int num = max ? 0 : 9999999;
    recursiveDive(num, node, max);
    return num;
}

// even the bool is passed by reference! SAVE. THEM. ALL!
void Holder::recursiveDive(int &num, Node* node, bool &max) {
    if (node == nullptr) return;
    if ((node->num > num && max) || (node->num < num && !max)) num = node->num;
    recursiveDive(num, node->left, max);
    recursiveDive(num, node->right, max);
}

// check for AVL condition in given tree
void Holder::getAVLCondition(Node *node) {
    if (node == nullptr) return;
    bool isAVL = true;
    recursiveAVLCheck(node, isAVL);
    std::cout << "\nAVL: " << (isAVL ? "yes" : "no");
    printStats(node);
}

// again, a lightweight recursive function to do some light magic
void Holder::recursiveAVLCheck(Node *node, bool &isAVL) {
    if (node == nullptr) return;
    recursiveAVLCheck(node->left, isAVL);
    recursiveAVLCheck(node->right, isAVL);
    int dif = abs(getDepth(node->left) - getDepth(node->right));
    std::cout << "\nbal(" << node->num << ") = " << dif;
    if (dif > 1) {
        isAVL = false;
        std::cout << " (AVL violation!)";
    }
}

// print statistics about the tree
void Holder::printStats(Node* node) {
    int sum = 0, counter = 0;
    recursiveDive(sum, node, counter);
    int min = getOuterLeft(node), max = getOuterRight(node), avg = sum/counter;
    std::cout << "\nmin: " << min << ", max: " << max << ", avg: " << avg;
}

// sum up all nums in tree
void Holder::recursiveDive(int &sum, Node *node, int &counter) {
    if (node == nullptr) return;
    sum += node->num;
    recursiveDive(sum, node->left, ++counter);
    recursiveDive(sum, node->right, counter);
}

// get the most left num (= smallest)
int Holder::getOuterLeft(Node *node) {
    if (node == nullptr) return -1;
    int left = getOuterLeft(node->left);
    if (left == -1) return node->num;
    else return left;
}

// get the most right num (= largest)
int Holder::getOuterRight(Node *node) {
    if (node == nullptr) return -1;
    int left = getOuterRight(node->right);
    if (left == -1) return node->num;
    else return left;
}

