// source aknowledgement: the link https://www.interviewbit.com/tutorial/merge-sort-algorithm/ helped me understand the implementation of merge sort
#include <vector>
#include <map>
#include <string>
#include <iostream>

int countOOO(std::vector<std::string> rankedListA, std::vector<std::string> rankedListB);
int mergeSortCount(std::vector<int>& vec, int first, int last);
int countOut(std::vector<int>& vec, int first, int mid, int last);

// countOOO computes the number of pairs of elements in rankedListA that are out of order in rankedListB
int countOOO(std::vector<std::string> rankedListA, std::vector<std::string> rankedListB) {
	//create two vectors of integers and map each string to a corresponding integer value
	std::vector <int> intListA;
	std::vector <int> intListB;;
	std::map<std::string, int> listMap;
	int num = 1;
	for(std::vector<std::string>::iterator itA = rankedListA.begin(); itA != rankedListA.end(); itA++) { //O(nlogn)
		listMap.insert(std::make_pair(*itA, num)); //O(logn)
		intListA.push_back(num); //O(1)
		num++;
	}
	for(std::vector<std::string>::iterator itB = rankedListB.begin(); itB != rankedListB.end(); itB++) { //O(nlogn)
		intListB.push_back(listMap.at(*itB)); //O(logn)
	}
	int size = intListB.size();
	int count = mergeSortCount(intListB, 0, size - 1); //O(nlogn)
	return count;
}

int mergeSortCount(std::vector<int>& vec, int first, int last) { //O(nlogn) from the Master theorem T(n) = 2*T(n/2) + O(n) (a=2, b=2, d=1)
	//int count = 0;
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	if(first < last) {
		int half = first + (last - first)/2;
		count1 = mergeSortCount(vec, first, half); //divide the vector into two halves and call the function again on each subvector to find the number of out of 
		count2 = mergeSortCount(vec, half + 1, last);  //order elements for each half (recursive part)
		count3 = countOut(vec, first, half + 1, last); //counting out of order elements for each subvector in O(n) time
	}
	return count1 + count2 + count3; //add all the counts to get the total count
}

int countOut(std::vector<int>& vec, int first, int half, int last) { //O(n)
	int diffCount = 0;
	int i, j, k;
	int newSize = last - first + 1;
    std::vector<int> newVec(newSize);
	for(i = first, j = half, k = 0; i <= (half - 1) && j <= last; k++){ //O(n)
		 if (vec.at(i) <= vec.at(j)){
            newVec.at(k) = vec.at(i++);
        }
        else{
            newVec.at(k) = vec.at(j++);
            diffCount += half - i; //all elements remaining in the first subvector would also be bigger and therefore out of order
        }
	}

	while (i <= (half - 1)) //O(n) //add the remaining elements of the non emtpy vector to the sorted vector
    {
        newVec.at(k++) = vec.at(i++);
    }

    while (j <= last) //O(n)
    {
        newVec.at(k++) = vec.at(j++);
    }

    for (int l = 0; l < newSize; l++) //O(n)
    {
        vec.at(l + first) = newVec.at(l); //add the sorted elements to their corresponding index in the original vector
    }
	
return diffCount;
}

/*int main() {
	std::vector<std::string> myVecA = {"Burgers", "Pizza", "Pasta", "Salad", "Sushi", "Tacos", "Burritos"};
	std::vector<std::string> myVecB = {"Tacos", "Pizza", "Sushi", "Salad", "Pasta", "Burritos", "Burgers"};
	std::cout << countOOO(myVecA, myVecB) << " elements are out of order" << std::endl;
	return 0;
}*/