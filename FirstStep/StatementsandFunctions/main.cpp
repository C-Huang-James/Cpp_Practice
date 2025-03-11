#include <iostream>

int addnumbers( int first_param, int second_param){

    int result = first_param + second_param;
    return result;

}


int main(){

    int first_number {3}; // Statement
    int second_number {7};

    std::cout << "First number : " << first_number << std::endl;
    std::cout << "Second number : " << second_number << std::endl;

    int sum = first_number + second_number;
    std::cout << "Sum : " << sum << std::endl;

    sum = addnumbers(25,7);
    std::cout << "Sum : " << sum << std::endl;

    std::cout << "Sum : " << addnumbers(3,42) << std::endl;
    return 0;
}