#include <iostream> 
#include <string>
#include "sorta.h"

int main() {
    std::string myString = "pneumonoultramicroscopicsilicovolcanoconiosis";
    std::cout << myString << " sorted by frequency: " << sortByFreq(myString) << std::endl;
    return 0;
}