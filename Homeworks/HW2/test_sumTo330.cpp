//Code to test sumTo330.cpp
#include <iostream>
#include <vector>

int sumTo330(std::vector<int> nums);

int main(){
    std::vector<int>nums = {20, 120, 200, 5};
    std::cout << "The sum of three numbers that is closest to 330 is " << sumTo330(nums) << std::endl;
}


int sumTo330(std::vector<int> nums) {
	int sum = 0;
	int size = nums.size();
	for (int i = 0; i < size; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			for (int k = j+1; k < size; k++){
				int newSum = nums.at(i) + nums.at(j) + nums.at(k);
				if(abs(newSum - 330) < abs(sum - 330)){
					sum = newSum;
				} 
				else if (abs(newSum - 330) == abs(sum - 330)){
					if (newSum <= sum){
						sum = newSum;
					}
				}
			}

		}
	}
	return sum; // don't forget to change this
}