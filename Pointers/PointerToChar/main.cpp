#include <iostream>

int main(){
    //Declaring pointers
	int * p_number {};	// can only store an address of 
						// a variable of type int

	double * p_fractional_number {};	// can only store an address of 
										// a variable of type double

	//Explicitly initializie to nullptr
	int * p_number1{nullptr};
	double * p_fractional_number1 {nullptr};

	//Pointers to different variables are of the same size
	std::cout << "sizeof(int) : " << sizeof(int) << std::endl;
	std::cout << "sizeof(double) : " << sizeof(double) << std::endl;
	std::cout << "sizeof(int*) : " << sizeof(int*) << std::endl;
	std::cout << "sizeof(double*) : " << sizeof(double*) << std::endl;
	std::cout << "sizeof(p_number1) : " << sizeof(p_number1) << std::endl;
	std::cout << "sizeof(p_fractional_number1) : " << sizeof(p_fractional_number1) << std::endl;

	int*  p_number2{nullptr};
	int * p_number3{nullptr};
	int  *p_number4{nullptr};	//All work the same
								// int *p_number4 format is easier
								// to understand when you have multiple 
								// variables declared on the same line

	int *p_number5{}, other_int_var{};
	int* p_number6{}, other_int_var1{};	// Confusing as you wonder if other_int_var1
										// is also a pointer to int. It is not
										// The structure is exactly the same for the 
										// previous statement

	std::cout << "sizeof(p_number5) : " << sizeof(p_number5) << std::endl;
	std::cout << "sizeof(other_int_var) : " << sizeof(other_int_var) << std::endl;
	std::cout << "sizeof(p_number6) : " << sizeof(p_number6) << std::endl;
	std::cout << "sizeof(other_int_var1) : " << sizeof(other_int_var1) << std::endl;

	// It is better to separate these declarations on different lines though
	int *p_number7{};
	int other_int_var2{}; // No room for confusion this time


	//Initializing pointers and assigning them data

	//We know thta pointers store addresses of variables
	int int_var {43};
	int *p_int{&int_var};	// p_int_var now holds the address of int_var

	std::cout << "int_var : " << int_var << std::endl;
	std::cout << "p_int (Address in memory) : " << p_int << std::endl;

	// You can also change the address stored in a pointer any time
	int int_var1 {65};

	int_var1 = 126;

	p_int = &int_var1; // Assign a different address to the pointer
	std::cout << "p_int (with different address) : " << p_int << std::endl;

	int *p_int1{nullptr};
	double double_var{33};
	//p_int = &double_var; // Error: Cannot assign address of double to int pointer 

	// Dereferencing the pointer
	int *p_int2{nullptr};
	int int_data {56};
	p_int2 = &int_data;

	std::cout << "value : " << *p_int2 << std::endl; 


	return 0;
}