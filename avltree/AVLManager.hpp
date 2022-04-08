#ifndef AVLTREE_AVLMANAGER_HPP
#define AVLTREE_AVLMANAGER_HPP

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "Holder.hpp"
#include "Display.hpp"

using namespace std;

class AVLManager {
public:
    AVLManager();
    void feedNewTree();
    void printError(int error);

private:
    void setupTree();
    std::vector<Holder*> holders;
    Display* display;
};


#endif //AVLTREE_AVLMANAGER_HPP
