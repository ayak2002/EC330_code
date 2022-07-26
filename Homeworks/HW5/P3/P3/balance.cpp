#include "node.h"
#include <cmath>

int countNodes(node* root) {
    int count = 1;
    if(root->left != NULL) {
        count += countNodes(root->left);
    }
    if(root->right != NULL) {
        count += countNodes(root->right);
    }
    return count;
}
bool isWeightBalanced(node* root, int k) { 
    int count_left = 0;
    int count_right = 0;
    if(root->left != NULL) {
        count_left += countNodes(root->left);
    }
    if(root->right != NULL) {
        count_right += countNodes(root->right);
    }
    int diff = abs(count_left - count_right);
    if(diff > k) {
        return false;
    }
    else if((root->right == NULL) && (root->left == NULL)) {
        return true;
    }
    else if(root->left == NULL){
        return isWeightBalanced(root->right, k);
    }
    else if(root->right == NULL) {
        return isWeightBalanced(root->left, k);
    }
    else {
        return (isWeightBalanced(root->left, k) && isWeightBalanced(root->right, k));
    }
}

