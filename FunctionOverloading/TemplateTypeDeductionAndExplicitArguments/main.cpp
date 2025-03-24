#include <iostream>

template <typename T> T maximum(T a, T b); // Should pass in the same type

int main(){

    int a{10};
    int b{23};
    double c{34.7};
    double d{45.6};
    std::string e{"hello"};
    std::string f{"world"};

    maximum(a, b); //int type deduced
    maximum(c, d); //double type deduced
    maximum(e, f); //string type deduced

    maximum<double>(c, d);  // explicitly say that we want the double version called, 
                            // if an instance is not there already, it will be created

    maximum<double>(a, c);  // WOrks, even if parameters are of different types,
                            // there is implicit conversion from int to double
                            // for the first parameter

    // maximum<double>(a,e); // Error, no implicit conversion from int to string

    std::cout << "max(int) : " << maximum(a, b) << std::endl; // int version created
    std::cout << "max(double) : " << maximum(c, d) << std::endl; // double version created
    std::cout << "max(string) : " << maximum(e, f) << std::endl; // string version created

    return 0;
}

template <typename T> T maximum(T a, T b){
    return a > b ? a : b; // a and b must support the > operator
};

