#include <iostream>
#include <concepts> 

template <typename T>
concept MyIntegral = std::is_integral_v<T>;

template <typename T>
concept Multipliable = requires(T a, T b){
    a * b; //Just make sure syntax is valid
};

template <typename T>
concept Incrementable = requires(T a){
    a+=1;
    ++a;
    a++;
};

//Syntax1
/*
template <typename T>
requires MyIntegral<T>
T add (T a, T b){
    return a + b;
}*/

//Syntax2
/*
template <MyIntegral T>
T add (T a, T b){
    return a + b;
}*/

//Syntax3
/*
MyIntegral auto add(MyIntegral auto a, MyIntegral auto b){
    return a + b;
}
*/




template <typename T>
requires Incrementable<T>
T add (T a, T b){
    return a + b;
}



int main(){ 

    double x{6};
    double y{7};

    std::cout << add(x, y) << std::endl;


    return 0;
}

