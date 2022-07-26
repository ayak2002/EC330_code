unsigned long genA(int n) {
	/* your code here */
	int index = n-1;
    if(index <= 1){
        return 1;
    }
    else{
        int result = 0;
        int first = 0;
        int last = index - 1;
        while (first<=last){
            unsigned long callFirst = genA(first + 1);
            unsigned long callLast = genA(last + 1);
            if(first == last){
                result += callFirst * callLast;
            }
            else{
                result += callFirst * callLast * 2;
            }
            first++;
            last--;
        }
        return result;
	} /* don't forget to change the return value */
}