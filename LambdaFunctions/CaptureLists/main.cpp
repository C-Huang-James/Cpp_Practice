#include <iostream>

int main(){

    double a{10};
    double b{20};

    auto func = [a, b](){
        std::cout << "a + b : " << a + b << std::endl;
        std::cout << "a: " << a << ", b: " << b << std::endl;
    };
    func();
    
    // Pass by value (copy value)
    std::cout << std::endl;
    std::cout << "Lambda function with pass by value" << std::endl;
    int c{42};
    auto func1 = [c](){
        std::cout << "Inner value : " << c  << ", inner &" << &c << std::endl;
    };

    for (size_t i; i < 5 ; ++i){
        std::cout << "Outer value : " << c << ", outer &" << &c << std::endl;
        func1();
        ++c;
    }

    // Pass by reference 
    std::cout << std::endl;
    std::cout << "Lambda function with pass by reference" << std::endl;
    auto func2 = [&c](){
        std::cout << "Inner value : " << c << ", inner &" << &c << std::endl;
    };

    for (size_t i; i < 5 ; ++i){
        std::cout << "Outer value : " << c << ", outer &" << &c << std::endl;
        func2();
        ++c;
    }

    return 0;
}
