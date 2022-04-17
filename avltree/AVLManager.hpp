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
    Holder* getTree(string command);


private:
    int feedNewTree(string path);
    void printError(int error);

    std::vector<Holder*> holders;

};


#endif //AVLTREE_AVLMANAGER_HPP
