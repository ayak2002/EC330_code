/*https://medium.com/swlh/using-the-two-pointer-technique-bf642ab05661 This website helped me get my idea. It explains the concept of the two pointer
technique, so I decided to combine this technique with iteration to find the sum of three numbers instead of two*/
#include <vector>
#include <algorithm>
int sumTo330(std::vector<int> nums) {
	std::sort(nums.begin(), nums.end());
	int sum = nums.at(0) + nums.at(1) + *(nums.end()-1);
	for(std::vector<int>::iterator it = nums.begin(); it != nums.end(); it++){
		std::vector<int>::iterator num1 = it + 1;
		std::vector<int>::iterator num2 = nums.end() - 1;
		while (num1 < num2){
			int newSum = (*it) + (*num1) + (*num2);
			if(abs(330 - newSum) < abs(330 - sum)){
				sum = newSum;
			}
			else if(abs(330 - newSum) == abs(330 - sum)){
				if(newSum < sum){
					sum = newSum;
				}
			}
			if(newSum <= 330){
				num1++;
			}
			else{
				num2--;
			}
		}
	}
	return sum; 
}
