#include <iostream>

void say_age(int& age); //Declaration


int main(){
    int age{23}; //Local
    std::cout << "age (before call) : " << age << ", &age : " << &age << std::endl;
    say_age(age);
    std::cout << "age (after call) : " << age << ", &age : " << &age << std::endl;


    return 0;
}

void say_age(int& age){ //Parameter
    ++age; //dereference
    std::cout << "Reference of age : " << &age << std::endl;
    std::cout << "Hello, you are " << age << " years old." << " &age : " << &age <<std::endl;
}

