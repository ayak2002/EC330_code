#include <string>
#include "sorta.h"
std::string sortByFreq(std::string s) {
    std::string res = "";
    int freqArr[26] = {0};
    for (int i = 0; i < s.length(); i++){
		int index = static_cast<int>(s[i]) - 97; //because the letter a's ascii value is 97
		freqArr[index]++; //increments the count of the corresponding letter
	}
    int PrevFreq = 0;
    while (res.length() != s.length()) {
        int lowestFreq = s.length();
        for(int i = 0; i < 26; i++) {
            if((freqArr[i] < lowestFreq) && (freqArr[i] > PrevFreq)){
                lowestFreq = freqArr[i];
            }
        }
        for(int i = 0; i < 26 ; i++) {
            if(freqArr[i] == lowestFreq){
                for(int j = 0; j < lowestFreq; j++) {
                    res.push_back(static_cast<char>(i + 97));
                }
            }
        }
        PrevFreq = lowestFreq;
    }
    return res;
}