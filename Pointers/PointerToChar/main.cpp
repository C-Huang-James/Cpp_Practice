#include <iostream>
#include <string>

int main(){
    char *p_char_var {nullptr};
	char char_var {'A'};

	p_char_var = &char_var;

	std::cout << "The value stored in p_char_var is : " << *p_char_var << std::endl;

	char char_var1 {'C'};
	p_char_var = &char_var1;

	std::cout << "The value stored in p_char_var is : " << *p_char_var << std::endl;

	/*
	char *p_message { "Hello World!"}; // string literal is made up of const char => complie error
	*/
	// can do it like this 
	const char * p_message {"Hello World!"};


	// Printing out 
	std::cout << "The message is : " << p_message << std::endl;
	std::cout << "The value stored at p_message is : " << *p_message << std::endl;

	// *p_message = 'B'; //Complier error
	// std::cout << "The message is (after modification of first char to B) : " << p_message << std::endl;

	// Alow users to modify he string
	char message1[] {"Hello World!"}; 
	message1[0] = 'B';
	std::cout << "The message is (after modification of first char to B) : " << message1 << std::endl;



	return 0;
}