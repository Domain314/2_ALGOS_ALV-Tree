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

Node* Holder::traverseTree(Node* node, int num) {
    if (node->num == num) return node;
    else if (node->num < num) {
        if (node->right != nullptr) return traverseTree(node->right, num);
        else return node;
    } else if (node->num > num) {
        if (node->left != nullptr) return traverseTree(node->left, num);
        else return node;
    }
    //return node;
    return nullptr;
}

// return 0 or error code
int Holder::insertNode(int num) {
    if (head == nullptr) { setHead(new Node(num)); return 0; }
    else {
        Node* last = traverseTree(head, num);
        if (last->num == num) return 1;
        else if (last->num < num) { last->right = new Node(num); return 0; }
        else if (last->num > num) { last->left = new Node(num); return 0;}
        else return 2;
    }
    return 3;
}

Node* Holder::searchNode(int num) {
    return head; // to do
}

void Holder::deleteNode(int num) {
    //to do
}

int Holder::getDepth(Node* node) {
    int depth = 0, maxDepth = 0;
    recursiveDive(depth, maxDepth, node);
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

int Holder::getMaxNum(Node* node) {
    int maxNum = 0;
    recursiveDive(maxNum, node);
    return maxNum;
}

void Holder::recursiveDive(int &maxNum, Node* node) {
    if (node == nullptr) return;
    if (node->num > maxNum) maxNum = node->num;
    recursiveDive(maxNum, node->left);
    recursiveDive(maxNum, node->right);
}
