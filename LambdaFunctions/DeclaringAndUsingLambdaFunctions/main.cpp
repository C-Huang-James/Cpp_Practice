#include <iostream>

//Lambda function signature:
//[capture list] (parametrers) -> return type {function body};

auto func = [](){std::cout << "Hello World!" << std::endl;};
int main(){

    func();

    //Can also do this
    [](){std::cout << "Hello World!" << std::endl;}();

    //Lambda function that takes parameters
    [](double a, double b){std::cout << a + b << std::endl;}(5.0, 6.0);

    //Lambda function that returns a value (can specify return type)
    auto result = [](double a, double b) -> double {return a + b;}(5.7, 6.55);
    std::cout << "result : "<< result << ", sizeof(result) : " <<sizeof(result)  << std::endl;
    

    //Print result directly
    std::cout << "result : " << [](double a, double b){return (a+b);}(12.1, 5.7) << std::endl;
    return 0;
}
