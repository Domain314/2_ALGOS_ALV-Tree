#ifndef AVLTREE_HOLDER_HPP
#define AVLTREE_HOLDER_HPP

#include "Node.hpp"
#include <stdlib.h>
#include <iostream>

class Holder {
public:
    Holder();
    void setHead(Node* newHead);
    Node* getHead();

    Node* searchTreeLast(Node* node, int num);
    int insertNode(int num);

    int searchNode(Node *base, Node *search);
    Node* searchTree(Node *base, int num);
    void searchSingle(Node *base, int num);
    void printPath(Node* node, int num);

    int getDepth(Node* node);
    int getMinMaxNum(Node* node, bool max);
    void recursiveDive(int &num, Node* node, bool &max);
    void recursiveDive(int &depth, int &maxDepth, Node* node);
    void recursiveDive(int &sum, Node *node, int &counter);

    void getAVLCondition(Node* node);
    void recursiveAVLCheck(Node* node, bool &isAVL);

    void printStats(Node* node);
    int getOuterLeft(Node* node);
    int getOuterRight(Node* node);






private:
    Node* head;
};


#endif //AVLTREE_HOLDER_HPP
