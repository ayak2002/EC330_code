char findOdd(char arr[], int arr_size) {
	/* your code here */
	char oddChar;
	int countArr[26]; //initialize an array whose size is the number of letters in the alphabet.
	for (int i = 0; i<26; i++){
		countArr[i] = 0; //initialize all elements to 0
	}
	for (int i = 0; i < arr_size; i++){
		int index = static_cast<int>(arr[i]) - 97; //because the letter a's ascii value is 97
		countArr[index]++; //increments the count of the corresponding letter
	}	
	for(int i = 0; i < arr_size; i++){
        int index = static_cast<int>(arr[i]) - 97;
        if ((countArr[index] % 2) != 0){ //check if the letter appears an odd number of times
            oddChar = arr[i];
        }
	}
	return oddChar; /* don't forget to change the return value */
}