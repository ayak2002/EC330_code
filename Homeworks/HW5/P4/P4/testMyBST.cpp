#include <iostream>
#include "MyBST.h"

int main() {
    MyBST myTree;
    myTree.insert(2);
    myTree.insert(1);
    myTree.insert(3);
    myTree.insert(4);

    MyBST myTree2;
    myTree2.insert(3);
    myTree2.insert(2);
    myTree2.insert(1);
    myTree2.insert(4);

    vector<Rotation> rotationVec = myTree.transform(myTree2);
    for(int i = 0; i < rotationVec.size(); i++){
        rotationVec[i].print();
    }
}