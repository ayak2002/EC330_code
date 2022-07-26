#include "balancedDivide.h"

bool findSum(std::vector<int> input, std::vector<int> &solInd, int target, int ind){
    bool posSum = false; //boolean tells if making a sum with a certain element of the input array is possible
    if(ind < input.size()){
        if (target == 0){
            return true;
        }
        else if(input.at(ind) > target){
            return findSum(input, solInd, target, ind + 1); //if an element is bigger than the target, look at the next element without including the current element
        }
        else if(findSum(input, solInd, target - input.at(ind), ind + 1)){ //if we can include the current element, return true and push the index of the element to solInd
            posSum = true;
            solInd.push_back(ind);
        }
        else if(findSum(input, solInd, target, ind + 1)){ //if we cannot include the current element, move on to the next element without including the current one
            posSum = true;
        }
    }
    return posSum;
}

Assignment balancedDivide(std::vector<int> const &birthdays) {
    int target = static_cast<int>(std::accumulate(birthdays.begin(), birthdays.end(), 0)/2);
    std::vector<int> groupA;
    std::vector<int> groupB;
    std::vector<int> solInd = {};
    int diff = 0;
    while(!findSum(birthdays, solInd, target, 0)){  //optimal choice would be sum/2 for each group, if not possible, increment difference and target by 1
        diff++;
        target++;
        solInd = {};
    }
    for (int i = 0; i < birthdays.size(); i++){
        if(count(solInd.begin(), solInd.end(), i)){
            groupA.push_back(birthdays.at(i));
        }
        else{
            groupB.push_back(birthdays.at(i));
        }
    }
    return Assignment(diff, groupA, groupB);
}

//main function for testing purposes
int main(){
    std::vector<int> target = {30, 47, 23, 100, 45, 25, 31,89, 29, 62};
    Assignment a = balancedDivide(target);
    a.printAssignment();
}


