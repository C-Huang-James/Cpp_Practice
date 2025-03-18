#include <iostream>
#include "compare.h" //Preprocessor
#include "Operation.h"

int main(){

    int maximum = max(10, 5);
    std::cout << "The maximum number is: " << maximum << std::endl;

    int minimum = min(10, 5);
    std::cout << "The minimum number is: " << minimum << std::endl;
    
    int mult = incr_mult(10, 5);
    std::cout << "The multiplication of the incremented numbers is: " << mult << std::endl;
    
    return 0;
}
