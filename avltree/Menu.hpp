#ifndef AVLTREE_MENU_HPP
#define AVLTREE_MENU_HPP

#include <iostream>
#include "AVLManager.hpp"
#include "Display.hpp"

class Menu {
public:
    Menu();
    void printMenu();
    void takeInput();

private:
    AVLManager *avlManager;
};


#endif //AVLTREE_MENU_HPP
