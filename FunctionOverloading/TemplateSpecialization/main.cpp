#include <iostream>
#include <cstring>

template <typename T> T maximum(T a, T b); 

// Template specialization for const char*
template <>
const char* maximum<const char*>(const char* a, const char* b){
    // doc : https//en.cppreference.com/w/c/string/byte/strcmp
    return std::strcmp(a, b) > 0 ? a : b;
}

int main(){ 

    int a{10};
    int b{23};
    double c{34.7};
    double d{45.6};
    std::string e{"hello"};
    std::string f{"world"};

    auto max_int = maximum(a, b); //int type deduced
    auto max_double = maximum(c, d); //double type deduced
    auto max_str = maximum(e, f); //string type deduced, not lenght of string, but the lexicographical order

    std::cout << "max(int) : " << max_int << std::endl; // int version created
    std::cout << "max(double) : " << max_double << std::endl; // double version created
    std::cout << "max(string) : " << max_str << std::endl; // string version created

    const char* g{"hello"};
    const char* h{"world"};

    auto max_str_c = maximum(g, h); //const char* type deduced

    std::cout << "max(const char*) : " << max_str_c << std::endl; // const char* version created
    return 0;
}

template <typename T> T maximum(T a, T b){
    return a > b ? a : b; // a and b must support the > operator
};

