#include <iostream>
#include "node.h"

int main() {
    node myNode1(1);
    node* node1 = &myNode1;
    node myNode2(2);
    myNode1.left = &myNode2;
    node* node2 = &myNode2;
    node myNode3(3);
    myNode1.right = &myNode3;
    node* node3 = &myNode3;
    node myNode4(4);
    myNode2.left = &myNode4;
    node* node4 = &myNode4;
    node myNode5(5);
    myNode3.left = &myNode5;
    node* node5 = &myNode5;
    node myNode6(6);
    myNode3.right = &myNode6;
    node* node6 = &myNode6;
    node myNode7(7);
    myNode4.left = &myNode7;
    node* node7 = &myNode7;
    std::cout << isWeightBalanced(node1, 0) << std::endl;
    std::cout << isWeightBalanced(node2, 1) << std::endl;
    std::cout << isWeightBalanced(node3, 0) << std::endl;
    std::cout << isWeightBalanced(node4, 1) << std::endl;
    return 0;
}