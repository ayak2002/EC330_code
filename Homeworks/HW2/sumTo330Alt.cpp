//This is an alternative to sumTo330.cpp. This algorithm relies on three nested loops to find in an array the sum of three numbers closest to 330. Time complexity: O(n^3)
#include <vector>
int sumTo330Alt(std::vector<int> nums) {
	int sum = nums.at(0) + nums.at(1) + nums.at(2);
	int size = nums.size();
	for (int i = 0; i < size; i++)
	{
		for (int j = i+1; j < size; j++)
		{
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