#include <iostream>


// Function templates are just blueprints.
// They are not real C++ code consumed by the complier.
// The compiler uses the blueprint to generate the actual code when it is needed.


// Can try it on https://cppinsights.io 
template <typename T> T maximum(T a, T b); // Should pass in the same type

int main(){

    int a{10};
    int b{23};

    // int *p_a{&a}; // If we try this, ths will be comparing the address
    // int *p_b{&b};

    double c{34.7};
    double d{45.6};

    std::string e{"hello"};
    std::string f{"world"};

    std::cout << "max(int) : " << maximum(a, b) << std::endl; // int version created
    std::cout << "max(double) : " << maximum(c, d) << std::endl; // double version created
    std::cout << "max(string) : " << maximum(e, f) << std::endl; // string version created

    return 0;
}

template <typename T> T maximum(T a, T b){
    return a > b ? a : b; // a and b must support the > operator
};

