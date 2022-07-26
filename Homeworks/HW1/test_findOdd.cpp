#include <iostream>
#define SIZE 13
using namespace std;

char findOdd(char[], int);

int main(){
    char charArray[SIZE] = {'c', 'b', 'd', 'a', 'c', 'd', 'b', 'b', 'b', 'a', 'e', 'e', 'f'};
    cout << "The letter appearing an odd number of times is: " << findOdd(charArray, SIZE) << endl;
    return 0;
}

char findOdd(char arr[], int arr_size) {
	char oddChar;
	int countArr[26]; //initialize an array whose size is the number of letters in the alphabet.
	for (int i = 0; i<26; i++){
		countArr[i] = 0; //initialize all elements to 0
	}
	for (int i = 0; i < arr_size; i++){
		int index = static_cast<int>(arr[i]) - 97; //because the letter a's ascii value is 97
		countArr[index]++;
	}	
	for(int i = 0; i < arr_size; i++){
        int index = static_cast<int>(arr[i]) - 97;
        if ((countArr[index] % 2) != 0){
            oddChar = arr[i];
        }
	}
	return oddChar; 
}