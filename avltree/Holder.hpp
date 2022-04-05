#ifndef AVLTREE_HOLDER_HPP
#define AVLTREE_HOLDER_HPP

#include "Node.hpp"

class Holder {
public:
    Holder();
    void setHead(Node* newHead);
    Node* getHead();

    Node* traverseTree(Node* node, int num);
    int insertNode(int num);
    Node* searchNode(int num);
    void deleteNode(int num);

private:
    Node* head;
};


#endif //AVLTREE_HOLDER_HPP
