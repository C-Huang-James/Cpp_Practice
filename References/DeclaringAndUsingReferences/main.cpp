#include <iostream>

int main(){

    int int_value {45};
    double double_value{33.65};

    int &reference_to_int_value_1{int_value}; // Assign throught initialization
    int &reference_to_int_value_2 = int_value; // Assign through assignment
    double &reference_to_double_value_1{double_value};
	
    //YYou have to declare and initialize in one statement
    //int &some_reference; // Error: declaration of reference variable 'some_reference' requires an initializer

    std::cout << "int_value : "<< int_value << std::endl;
    std::cout << "double_value : " << double_value << std::endl;
    std::cout << "reference_to_int_value_1 : " << reference_to_int_value_1 << std::endl;
    std::cout << "reference_to_int_value_2 : " << reference_to_int_value_2 << std::endl;
    std::cout << "reference_to_double_value_1 : " << reference_to_double_value_1 << std::endl;
    std::cout << "&int_value : "<< &int_value << std::endl;
    std::cout << "&double_value : " << &double_value << std::endl;
    std::cout << "&reference_to_int_value_1 : " << &reference_to_int_value_1 << std::endl;
    std::cout << "&reference_to_int_value_2 : " << &reference_to_int_value_2 << std::endl;
    std::cout << "&reference_to_double_value_1 : " << &reference_to_double_value_1 << std::endl;
    std::cout << "sizeof(int) : " << sizeof(int) << std::endl;
    std::cout << "sizeof(int&) : " << sizeof(int&) << std::endl;
    std::cout << "sizeof(reference_to_int_value_1) : " << sizeof(reference_to_int_value_1) << std::endl;


    //Modify through reference : changes reflect to original variable
    std::cout << std::endl;
    std::cout << "Modify through reference : changes reflect to original variable" << std::endl;

    reference_to_int_value_1 = 55; // Modify through reference
    double_value = 115.65; // Modify through original variable


    //Print out after modification of int_value
    std::cout << "int_value : "<< int_value << std::endl;
    std::cout << "double_value : " << double_value << std::endl;
    std::cout << "reference_to_int_value_1 : " << reference_to_int_value_1 << std::endl;
    std::cout << "reference_to_double_value_1 : " << reference_to_double_value_1 << std::endl;
    std::cout << "&int_value : "<< &int_value << std::endl;
    std::cout << "&double_value : " << &double_value << std::endl;
    std::cout << "&reference_to_int_value_1 : " << &reference_to_int_value_1 << std::endl;
    std::cout << "&reference_to_double_value_1 : " << &reference_to_double_value_1 << std::endl;


	return 0;
}
