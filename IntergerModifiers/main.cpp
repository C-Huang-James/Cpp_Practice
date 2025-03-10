#include <iostream>
#include <string>

int main(){
    
    signed int value1 {10};
    signed int value2 {-300};

    std::cout << "Value1 is: " << value1 << std::endl;
    std::cout << "Value2 is: " << value2 << std::endl;
    std::cout << "Size of value1 is: " << sizeof(value1) << std::endl;
    std::cout << "Size of value2 is: " << sizeof(value2) << std::endl;
    
    unsigned int value3 {10};
    // unsigned int value4 {-300}; // Complier error

    //short and long
    short short_var {-32768}; // 2 bytes
    short int short_int {455};
    signed short signed_short {122};
    signed short int signed_short_int {-456};
    unsigned short int unsigned_short_int {456};

    int int_var {55}; // 4 bytes
    signed signed_var {66};
    signed int signed_int {77};
    unsigned int unsigned_int {77};

    long long_var {88}; // 4 or 8 bytes
    long int long_int {33};
    signed long signed_long {44};
    signed long int signed_long_int {44};
    unsigned long int unsigned_long_int {44};

    long long long_long_var {888}; // 8 bytes
    long long int long_long_int {999};
    signed long long signed_long_long {444};
    signed long long int signed_long_long_int {1234};
    unsigned long long int unsigned_long_long_int {1234};

    std::cout << "Size of short_var is: " << sizeof(short_var) << std::endl;
    std::cout << "Size of short_int is: " << sizeof(short_int) << std::endl;
    std::cout << "Size of signed_short is: " << sizeof(signed_short) << std::endl;
    std::cout << "Size of signed_short_int is: " << sizeof(signed_short_int) << std::endl;
    std::cout << "Size of unsigned_short_int is: " << sizeof(unsigned_short_int) << std::endl;
    
    std::cout << "Size of int_var is: " << sizeof(int_var) << std::endl;
    std::cout << "Size of signed_var is: " << sizeof(signed_var) << std::endl;
    std::cout << "Size of signed_int is: " << sizeof(signed_int) << std::endl;
    std::cout << "Size of unsigned_int is: " << sizeof(unsigned_int) << std::endl;

    std::cout << "Size of long_var is: " << sizeof(long_var) << std::endl;
    std::cout << "Size of long_int is: " << sizeof(long_int) << std::endl;
    std::cout << "Size of signed_long is: " << sizeof(signed_long) << std::endl;
    std::cout << "Size of signed_long_int is: " << sizeof(signed_long_int) << std::endl;
    std::cout << "Size of unsigned_long_int is: " << sizeof(unsigned_long_int) << std::endl;

    std::cout << "Size of long_long_var is: " << sizeof(long_long_var) << std::endl;
    std::cout << "Size of long_long_int is: " << sizeof(long_long_int) << std::endl;
    std::cout << "Size of signed_long_long is: " << sizeof(signed_long_long) << std::endl;
    std::cout << "Size of signed_long_long_int is: " << sizeof(signed_long_long_int) << std::endl;
    std::cout << "Size of unsigned_long_long_int is: " << sizeof(unsigned_long_long_int) << std::endl;

    return 0;
}
