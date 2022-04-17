#include "Menu.hpp"

Menu::Menu() {
    avlManager = new AVLManager();
    std::cout << "Welcome";
    printMenu();
}

// main menu
void Menu::printMenu() {
    std::string command;
    std::cout << "\nEnter (t)reecheck [tree] [search-tree (optional)]\n";
    std::cin >> command;
    if (command == "t" || command == "treecheck") {
        takeInput();
    } else {
        printMenu();
    }
}

// take input one after another (divided by space or newline)
void Menu::takeInput() {
    std::string command;
    std::cin >> command;
    Holder* tree1 = avlManager->getTree(command);
    if (tree1 == nullptr) { printMenu(); return; }
    command = "";
    std::cin >> command;
    if (command == "t" || command == "treecheck") {
        takeInput();
    } else if (command == "d" || command == "display") {
        new Display(tree1);
        printMenu();
        return;
    } else {
        Holder* tree2 = avlManager->getTree(command);
        if (tree2 == nullptr) { printMenu(); return; }
        if (tree2->getDepth(tree2->getHead()) == 1) {
            tree1->searchSingle(tree1->getHead(), tree2->getHead()->num);
        } else {
            if (tree1->searchNode(tree1->getHead(), tree2->getHead())) {
                std::cout << "\nSubtree not found!\n";
            } else {
                std::cout << "\nSubtree found\n";
            }
        }
    }
    printMenu();
}
