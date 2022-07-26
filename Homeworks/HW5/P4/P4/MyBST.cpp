// source for getNext: https://ideone.com/18tLJ
//  MyBST.cpp
//  bst_transform
//
#include "MyBST.h"
#include <vector>
#include <string>

/**
 * Computes how to transform this MyBST into the target MyBST using rotations.
 * Returns a vector of rotations indicating which rotations around which nodes
 * must be performed to transform this into the target.
 *
 * IMPORTANT: We want to transform T1 into T2 so the call should look like
 * rotations = t1.transform(t2)
 */
MyBST::MyBST(){
    this->root = NULL;
}

vector<Rotation> MyBST::transform(MyBST target) {
  /*** Your implementation should go here. ***/
    vector<Rotation> rotVec;
    Node* targetRoot = target.root;
    while(targetRoot != NULL){
        Node* newRoot = this->search(targetRoot, this->root);
        while (getDepth(targetRoot, target.root) != getDepth(newRoot, this->root)) {
            Node* parentNode = getParent(this->root, newRoot->key);
            if(newRoot->key < parentNode->key){ 
                if(this->root->key == parentNode->key) {
                    this->root = this->rotateRight(parentNode);
                    Rotation rot(parentNode->key, ZIG);
                    rotVec.push_back(rot);
                }
                else{
                    Node* parentParentNode = this->getParent(this->root, parentNode->key);
                    if((parentNode->key) > (parentParentNode->key)) {
                        parentParentNode->right = this->rotateRight(parentNode);
                    }
                    else{
                        parentParentNode->left = this->rotateRight(parentNode);
                    }
                    Rotation rot(parentNode->key, ZIG);
                    rotVec.push_back(rot);

                }
            }
            else { 
                if(this->root->key == parentNode->key) {
                    this->root = this->rotateLeft(parentNode);
                    Rotation rot(parentNode->key, ZAG);
                    rotVec.push_back(rot);
                }
                else{
                    Node* parentParentNode = this->getParent(this->root, parentNode->key);
                    if((parentNode->key) > (parentParentNode->key)) {
                        parentParentNode->right = this->rotateLeft(parentNode);
                    }
                    else{
                        parentParentNode->left = this->rotateLeft(parentNode);
                    }
                    Rotation rot(parentNode->key, ZAG);
                    rotVec.push_back(rot);
                }
            }
        }
        targetRoot = getNext(target.root, targetRoot);
    }
    return rotVec;  	
}

// You can use the rotation functions below as a starting point, 
// or you can choose your own implementation strategy. 
Node* MyBST::rotateRight(Node* Q)
{
    Node* P = Q->left;
    Q->left = P->right;
    P->right = Q;
    return P;
}

Node* MyBST::rotateLeft(Node* P)
{
    Node* Q = P->right;
    P->right = Q->left;
    Q->left = P;
    return Q;
}

Node* MyBST::search(Node* target, Node* root)
{
    if((root->key == target->key) || (root == NULL)){
        return root;
    }
    else if(root->key < target->key) {
        return search(target, root->right);
    }
    else{
        return search(target, root->left);
    }
}


int MyBST::getDepth(Node* node, Node* root)
{
    if(node->key == root->key) {
        return 0;
    }
    else{
        return 1 + getDepth(getParent(root, node->key), root);
    }
}

Node* MyBST::getParent(Node* root, int keyVal)
{
    if (root == NULL){
       return NULL;
    }
    else if (root->key == keyVal) {
        return NULL;
    }
    else if(root->left == NULL && root->right == NULL){
       return NULL;
    }
    else if((root->right != NULL && root->right->key == keyVal) || (root->left != NULL && root->left->key == keyVal)){
       return root;
    }
    else if(root->key < keyVal){
       return getParent(root->right, keyVal);
    }
    else if(root->key > keyVal){
       return getParent(root->left, keyVal);
    }
}

Node* MyBST::getNext(Node* root, Node* node){ 
	vector<Node*> vec;
	if(root == NULL || node == NULL)
		return NULL;
	if(node->left != NULL) {
		return node->left;
    }
	if(node->right != NULL) {
		return node->right;
    }
    while(root->key != node->key){
		vec.push_back(root);
		if(node->key < root->key)
			root=root->left;
		else
			root=root->right;
	}
	for(int i=vec.size()-1; i>=0; i--){
		if(vec[i]->right)
		{
			if(node!=vec[i]->right)
				return vec[i]->right;
		}
		node = vec[i];
	}
	return NULL;
}

/*
int main() {
    MyBST myTree;
    myTree.insert(1);
    myTree.insert(2);
    myTree.insert(3);
    myTree.insert(4);
    myTree.insert(5);
    myTree.insert(6);  
    myTree.insert(7);
    myTree.insert(8);
    myTree.insert(9);
    myTree.insert(10);
    myTree.insert(11);
    myTree.insert(12);
    myTree.insert(13);
    myTree.insert(14);
    myTree.insert(15);
    myTree.insert(16);  
    myTree.insert(17);
    myTree.insert(18);
    myTree.insert(19);
    myTree.insert(52);
    myTree.insert(31);
    myTree.insert(23);

    MyBST myTree2;
    myTree2.insert(1);
    myTree2.insert(14);
    myTree2.insert(5);
    myTree2.insert(9);
    myTree2.insert(15);
    myTree2.insert(3);  
    myTree2.insert(11);
    myTree2.insert(18);
    myTree2.insert(13);
    myTree2.insert(10);
    myTree2.insert(8);
    myTree2.insert(4);
    myTree2.insert(2);
    myTree2.insert(19);
    myTree2.insert(7);  
    myTree2.insert(16);
    myTree2.insert(6);
    myTree2.insert(17);
    myTree2.insert(12);
    myTree.insert(31);
    myTree.insert(23);
    myTree.insert(52);

    vector<Rotation> rotationVec = myTree.transform(myTree2);
    for(int i = 0; i < rotationVec.size(); i++){
        std::cout<<rotationVec[i].print()<<std::endl;
    }
    return 0;
}*/