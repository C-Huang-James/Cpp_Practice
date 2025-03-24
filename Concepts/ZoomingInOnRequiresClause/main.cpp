#include <iostream>
#include <concepts> 

// Nested requirement
template <typename T>
concept TinyType = requires (T t){
    sizeof(T) <= 4; // Simple requirement : Only enforce the syntax (T can be an argument of sizeof)
    requires sizeof(T) <= 4; // Nested requirement : Enforce the syntax and the semantics (T must be an argument of sizeof)
};

// Compound requirement
template <typename T>
concept Addable = requires (T a, T b){
    //noexcept is optional
    {a+b} noexcept -> std::convertible_to<int>; //Compound requirement
    //Check if a + b is valid syntax, doesn't throw exceptions(optional), and the rsult 
    //is convertible to int (optional)
};

/*
TinyType auto add(TinyType auto a, TinyType auto b){
    return a + b;
}
*/

Addable auto add(Addable auto a, Addable auto b){
    return a + b;
}

int main(){ 

    // If only the first line, then the code will compile (TinyTpye case)
    // If only the second line, then there will be a compilation error
    // double x{67};
    // double y{56};

    char x{67};
    char y{56};

    //THe string type is not convertible to int, so the code will not compile
    /*
    std::string x{"Hello"};
    std::string y{"World"}; 
    */

    auto result = add(x, y);
    std::cout << "result : " << result << std::endl;
    std::cout << "sizeof(result) : " << sizeof(result) << std::endl;

    return 0;
}

