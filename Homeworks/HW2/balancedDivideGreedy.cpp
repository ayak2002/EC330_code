//This code takes a vector containing birthdays (ints from 1 to 31) and creates two balanced groups (aka the difference between the sums of the birthdays of each group is minimized)
#include "balancedDivide.h"

Assignment balancedDivide(std::vector<int> const &birthdays) {
	std::vector<int> groupA;
	std::vector<int> groupB;
	std::vector<int> sortedBdays;
	for(std::vector<int>::const_iterator it = birthdays.begin(); it != birthdays.end(); it++){
		sortedBdays.push_back(*it);
	}
	std::sort(sortedBdays.begin(), sortedBdays.end());
	for(std::vector<int>::reverse_iterator it = sortedBdays.rbegin(); it != sortedBdays.rend(); it++){
		int sumA = std::accumulate(groupA.begin(), groupA.end(), 0);
		int sumB = std::accumulate(groupB.begin(), groupB.end(), 0);
		if(sumA <= sumB){
			groupA.push_back(*it);
		}
		else{
			groupB.push_back(*it);
		}
	}
	int diff = abs(std::accumulate(groupA.begin(), groupA.end(), 0) - std::accumulate(groupB.begin(), groupB.end(), 0));
	return Assignment(diff, groupA, groupB); // Don't forget to change this
}
