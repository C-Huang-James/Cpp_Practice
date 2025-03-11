#include <iostream>
#include <iomanip>

int main(){
    
    int var1{123}; //Declare and initialize
    std::cout << "var1: " << var1 << std::endl;

    var1 = 55; // Assign
    std::cout << "var1: " << var1 << std::endl;

    std::cout << std::endl;

    std::cout << "--------------------------------" << std::endl;

    std::cout << std::endl;

    bool state{false}; // Declare and initialize
    std::cout << std::boolalpha;
    std::cout << "state: " << state << std::endl;

    state = true; // Assign

    std::cout << "state: " << state << std::endl;


    //Auto type deduction
    auto var3{333u}; //Decalre and initialize with type deduction
    var3 = -22; // Assign

    std::cout << "var3: " << var3 << std::endl;

    return 0;
}
