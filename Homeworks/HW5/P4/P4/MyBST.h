#ifndef __MYBST_H__
#define __MYBST_H__

#include "BST.h"
#include <vector>
#include <string>

class MyBST : public BST
{
    using BST::BST;
    public:
        MyBST();
        vector<Rotation> transform(MyBST target);
        Node* search(Node* target, Node* root);
        int getDepth(Node* target, Node* root);
        Node* getParent(Node* node, int key);
        MyBST getSub(Node* root);
        Node* CopyTree(Node* TargetRoot);
        Node* getNext(Node* root, Node* node);
    private:
        Node* rotateRight(Node* Q);
        Node* rotateLeft(Node* P);
};

#endif /* __MYBST_H__*/