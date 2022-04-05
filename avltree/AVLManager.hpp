#ifndef AVLTREE_AVLMANAGER_HPP
#define AVLTREE_AVLMANAGER_HPP

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "Holder.hpp"

using namespace std;

class AVLManager {
public:
    AVLManager();
    void feedNewTree();
    void printError(int error);

private:
    std::vector<Holder*> holders;
};


#endif //AVLTREE_AVLMANAGER_HPP
