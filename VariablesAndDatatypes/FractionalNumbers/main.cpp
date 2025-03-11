#include <iostream>
#include <iomanip>

int main(){
    
    // Decalre and initialize the variables
    float number1 {1.12345678901234567890f}; // Precision : 7, suffixes with f (important when initializing)
    double number2 {1.12345678901234567890}; // Precision : 15
    long double number3 {1.12345678901234567890L}; // Precision : 15+

    //Print out the sizes 
    std::cout << "Size of float: " << sizeof(float) << " bytes" << std::endl;
    std::cout << "Size of double: " << sizeof(double) << " bytes" << std::endl;
    std::cout << "Size of long double: " << sizeof(long double) << " bytes" << std::endl;


    //Precision
    std::cout << std::setprecision(20); //Control the precision from std::cout
    std::cout << "number 1 is: " << number1 << std::endl; // 7 digits
    std::cout << "number 2 is: " << number2 << std::endl; // 15 digits
    std::cout << "number 3 is: " << number3 << std::endl; // 15+ digits


    //Float problems : The precision is usually too limited
    //for a lot of applications
    float number4 {192400023.0f}; // error : narrowing conversion
    double number5 {192400023.0}; 

    std::cout << "number 4 is: " << number4 << std::endl;
    std::cout << "number 5 is: " << number5 << std::endl;
    
    std::cout << "--------------------------------" << std::endl;
    //Scientific notation
    double number6 {1.92400023e8};
    double number7 {1.924e8}; // Can ommit the lower 00023
                              // for simplicity if our application allows
    double number8 {0.00000000003498};
    double number9 {3.498e-11}; // Scientific notation

    std::cout << "number 5 is: " << number5 << std::endl;
    std::cout << "number 6 is: " << number6 << std::endl;
    std::cout << "number 7 is: " << number7 << std::endl;
    std::cout << "number 8 is: " << number8 << std::endl;
    std::cout << "number 9 is: " << number9 << std::endl;

    std::cout << "--------------------------------" << std::endl;

    // Infinity and Nan
    std::cout << std::endl;
    std::cout << "Infinity and NaN" << std::endl;

    double number10{5.6};
    double number11{};
    double number12{};

    //Infinity
    double result {number10 / number11};

    std::cout << number10 << "/" << number11 << " yields: " << result << std::endl;
    std::cout << result << " + " << number10 << " yields: " << result + number10 << std::endl;

    //NaN
    result = number11 / number12;

    std::cout << number11 << "/" << number12 << " yields: " << result << std::endl;
    
    return 0;
}
