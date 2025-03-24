#include <iostream>

template <typename T> T maximum( T a, T b); 
template <typename T> const T& maximum1(const T& a, const T& b); 

int main(){

    double a {23.5};
    double b {51.2};

    std::cout << "Out - &a: " << &a << std::endl;
    double max = maximum(a, b);
    double max1 = maximum1(a, b);
    std::cout << "max: " << max << std::endl;
    std::cout << "max1: " << max1 << std::endl;


    return 0;
}

template <typename T> T maximum(T a, T b){
    std::cout << "In - &a (Pass by value) : " << &a << std::endl;
    return a > b ? a : b; // a and b must support the > operator
};

template <typename T> const T& maximum1(const T& a, const T& b){
    std::cout << "In - &a (Pass by reference) : " << &a << std::endl;
    return a > b ? a : b; // a and b must support the > operator
};

