#include <iostream>
#include <concepts> 

template <typename T>
concept TinyType = requires (T t){
    sizeof(T) <= 4; //Simple requirement
    requires sizeof(T) <= 4; // Nested requirement
};

template <typename T>
// requires std::integral<T> || std::floating_point<T> // 1) OR operator
requires std::integral<T> && TinyType<T> // 2)
// requires std::integral<T> && requires ( T t){ // 3)
// 	sizeof(T) <=4; // Simple requirement
// 	requires sizeof(T) <= 4; // Nested requirement
// }
T add(T a, T b){
    return a + b;
}



int main(){ 

    int x{7};
    int y{5};

    // long long int x{7}; // Satisfy 1) but not others
    // long long int y{5};

    std::cout << "add(x,y) : " << add(x,y) << std::endl;

    return 0;
}

