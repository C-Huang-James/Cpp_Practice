#include <iostream>

int main(){

    int c{42};

    auto func = [=](){ // Pass by value (copy)
        std::cout << "Inner value : " << c << std::endl;
    };

    for (size_t i{} ; i<5; ++i){
        std::cout << "Outer value : " << c << std::endl;
        func();
        ++c;
    }

    // Pass by reference
    std::cout <<std::endl;
    std::cout << "Pass by reference" << std::endl;
    double d{3.14};

    auto func1 = [&](){ // Pass by reference
        std::cout << "Inner value c : " << c << std::endl;
        std::cout << "Inner value d : " << d << std::endl;
    };

    for (size_t i{} ; i<5; ++i){
        std::cout << "Outer value c : " << c << std::endl;
        std::cout << "Outer value d : " << d << std::endl;
        func1();
        ++c;
        d+=0.5;
    }

    return 0;
}
