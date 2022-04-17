#ifndef AVLTREE_DISPLAY_HPP
#define AVLTREE_DISPLAY_HPP

#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <chrono>
#include <unistd.h>
#include "Holder.hpp"

class Display {
public:
    Display(Holder* holder);
private:
    void printTree(Holder* holder);
    void recursiveDraw(int depth, int maxNumDigits, Node* node);
    void recursiveDraw(int depth, int maxNumDigits);
    void printDisplays();
    std::string drawNode(Node* node, int maxNumDigits);
    int getDigits(int num);
    std::vector<std::string> displays;
    int getEmptySpace(int depth);
    void calcEmptySpaces(int depth, int maxNumDigits);
    int recursiveSingleSpace(int depth, int maxDepth, int num);
    int recursiveDoubTripSpace(int depth, int maxDepth, int num);
    int recursiveQuadSpace(int depth, int maxDepth, int num);
    std::vector<int>emptySpaces;

};


#endif //AVLTREE_DISPLAY_HPP
