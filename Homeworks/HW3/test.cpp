#include <vector>
#include <map>
#include <string>
#include <iostream>

int merge_and_count(std::vector<int>& vector1, int alpha, int omega);
int mergeSortCount(std::vector<int>& vec, int first, int last);
int count_inversion(std::vector<int>& vector1, int a, int b);
int countOOO(std::vector<std::string> rankedListA, std::vector<std::string> rankedListB);


int merge_and_count(std::vector<int>& vector1, int alpha, int omega)
{
    int inversion = 0;
    int mid = (alpha + omega) / 2;
    int i = alpha;
    int j = mid + 1;
    int lastITR = 0;
    std::vector<int> final(omega - alpha + 1);


    while (i <= mid && j <= omega) {
        if (vector1[i] <= vector1[j])
        {
            final[lastITR++] = vector1[i++];
        }
        else
        {
            final[lastITR++] = vector1[j++];
            inversion += mid - i + 1;
        }
    }

    while (i <= mid)
    {
        final[lastITR++] = vector1[i++];
    }

    while (j <= omega)
    {
        final[lastITR++] = vector1[j++];
    }

    for (int k=0 ; k < omega-alpha+1; k++)
    {
        vector1[k+alpha] = final[k];
    }

return inversion;
}

int mergeSortCount(std::vector<int>& vec, int first, int last) { //O(nlogn) from the Master theorem T(n) = 2T(n/2) + O(n) (a=2, b=2, d=1)
	//int count = 0;
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	if(first < last) {
		int mid = (first/2) + (last/2);
		count1 = mergeSortCount(vec, first, mid); //divide the vector into two halves and call the function again on each subvector
		count2 = mergeSortCount(vec, mid + 1, last);
		count3 = merge_and_count(vec, first, last); //O(n)
	}
	return count1 + count2 + count3;
}

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
	for(std::vector<std::string>::iterator itB = rankedListB.begin(); itB != rankedListB.end(); itB++) { //O(n )
		intListB.push_back(listMap.at(*itB)); //O(1)
	}
	int size = intListB.size();
	int count = mergeSortCount(intListB, 0, size - 1); //O(nlogn)
	return count;
}

int main() {
	std::vector<std::string> myVecA = {"1", "2", "3", "4"};
	std::vector<std::string> myVecB = {"3", "1", "4", "2"};
	std::cout << countOOO(myVecA, myVecB) << " elements are out of order" << std::endl;
	return 0;
}