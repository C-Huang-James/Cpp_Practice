#include <iostream>

int main(){
    /*
	int *p_number {new int{67}}; // Points to some address, lets call that address1 

	//Should delete and reset here 

	int number{55};  //stack variable

	p_number = &number;		// Now p_number points to address2, but address1 is still in 
							// our program. But pur program has lost access to that memory
							// Memory has been leaked
	*/

	//Double allocation
	/*
	int *p_number1 {new int {55}};

	//Use th pointer
	//Should delete and reset here

	p_number1 = new int{44}; // memory with int{55} leaked.

	delete p_number1;
	p_number1 = nullptr;
	*/

	//Nested scopes with dynamically allocated memory
	{
		int *p_number2 {new int{57}};
	}
	//Memory with int{57} leaked
	// delete p_number2; // complie error

	std::cout << "Program ending well" << std::endl;
	return 0;
}