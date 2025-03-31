#include <iostream>
#include "cat.h"

//Intersting fact #1
/*
class Plane final{
    Plane()=default;
};

//This will trigger a compiler error
class FigherJet : public Plane{
    
};*/


int main(){

    Cat cat("short", "black cat");
    cat.miaw();

    std::cout << "Hello" << std::endl;
    return 0;
}