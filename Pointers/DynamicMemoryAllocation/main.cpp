#include <iostream>
#include <string>

int main(){
    
	//How we've used pointers so far
	/*
	int number {22}; // Stack
	int *p_number = &number;

	std::cout << std::endl;
	std::cout << "Decalring pointer and assigning address : " << std::endl;
	std::cout << "number : " << number << std::endl;
	std::cout << "p_number : " << p_number << std::endl;
	std::cout << "&number : " << &number << std::endl;
	std::cout << "*p_number : " << *p_number <<  std::endl;

	int *p_number1; // Uninitialized pointer, contains junk address
	int number1 {12};
	p_number1 = &number1; //Make it point to a valid address
	std::cout << std::endl;
	std::cout << "Uninitialized point : " << std::endl;
	std::cout << "*p_number1 : " << *p_number1 << std::endl;
	*/

	/*
	//BAD (crashing example)
	// Writing into uninitialized point through derefenrence
	int *p_number2; // Contains junk address : could be anything
	std::cout << "Writing in the 55" << std::endl;
	*p_number2 = 55; // Writing into junk address : BAD!
	std::cout << std::endl;
	std::cout << "Writing into uninitialized pointer through dereference" << std::endl;
	std::cout << "p_number2 : " << p_number2 << std::endl; // Reading from junk address.
	std::cout << "*p_number2 : "<< *p_number2 << std::endl;
	*/

	//Initialing pointer to null
	/*
	//int *p_number3{nullptr}; Also works
	int *p_number3 {};	// Initialized with pointer equivalent of zero : nullptr
						// A pointer pointing nowhere
	std::cout << "Writing into nullptr memory" << std::endl;
	*p_number3 = 55; // Writing into a point pointing nowhere : BAD, CRASH!
	std::cout << "Done writing!" << std::endl;

	std::cout << std::endl;
	std::cout << "Reading and writting throught nullptr : " << std::endl;
	*/

	/*
	//Dynamic heap memory
	int *p_number4{nullptr};
	p_number4 = new int;	// Dynamically allocate space ofr a single int on the heap 
							// This memory belongs to our program from now on. The system
							// can't use it for anything else, untill we return it.
							// After this line executes, we will have a valid memory location
							// allocated. The size of the allocated memory will be such that it
							// can store the type pointed to be the pointer

	*p_number4 = 77; // Writing into the dynamically allocated memory
	std::cout << std::endl;
	std::cout << "Dynamically allocating memory : " << std::endl;
	std::cout << "p_number4 : " << p_number4 << std::endl;
	std::cout << "*p_number4 : " << *p_number4 << std::endl;

	delete p_number4; // Return the memory to the operating system (OS)
	p_number4 = nullptr; // Reset the pointer to nullptr 
	*/

	// It is also possible to initialize the pointer with a vaild
	// address up on declaration. Not with a nullptr
	int *p_number5{ new int}; // Memory location contains junk value
	int *p_number6{ new int (22)}; // use direct initialization
	int *p_number7{ new int {23}}; // use uniform initialization

	std::cout << std::endl;
	std::cout << "Initialize with valid memory address ar declaration : " << std::endl;
	std::cout << "p_number5 : "	<< p_number5 << std::endl;
	std::cout << "*p_number5 : " << *p_number5 << std::endl; // Junk value 

	std::cout << "p_number6 : "	<< p_number6 << std::endl;
	std::cout << "*p_number6 : " << *p_number6 << std::endl;

	std::cout << "p_number7 : "	<< p_number7 << std::endl;
	std::cout << "*p_number7 : " << *p_number7 << std::endl;

	//Remeber to release the memory
	delete p_number5;
	p_number5 = nullptr;

	delete p_number6;
	p_number6 = nullptr;

	delete p_number7;
	p_number7 = nullptr;


	//Can reuse pointers
	p_number5 = new int(81);
	std::cout << "*p_number5 : " << *p_number5 << std::endl;

	delete p_number5;
	p_number5 = nullptr;

	//Calling delete twice on a pointer : BAD!
	p_number5 = new int(99);
	std::cout << "*p_number5 : " << *p_number5 << std::endl;

	delete p_number5;
	// delete p_number5; // BAD!
	p_number5 = nullptr;

	std::cout << "Program is ending well!" << std::endl;
	return 0;
}
