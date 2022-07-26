//code to test sumTo300Alt.cpp
#include <iostream>
#include <vector>

int sumTo330Alt(std::vector<int> nums);

int main(){
    std::vector<int>nums = {20, 120, 200, 5};
    std::cout << "The sum of three numbers that is closes to 330 is " << sumTo330Alt(nums) << std::endl;
}


int sumTo330Alt(std::vector<int> nums) {
	int sum = nums.at(0) + nums.at(1) + nums.at(2);
	int size = nums.size();
	for (int i = 0; i < size; i++){
		for (int j = i+1; j < size; j++){
			for (int k = j+1; k < size; k++){
				int newSum = nums.at(i) + nums.at(j) + nums.at(k);
				if(abs(330 - newSum) < abs(330 - sum)){
					sum = newSum;
				} 
				else if (abs(330 - newSum) == abs(330 - sum)){
					if (newSum <= sum){
						sum = newSum;
					}
				}
			}
		}
	}
	return sum; 
}