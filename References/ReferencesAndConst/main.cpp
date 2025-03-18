#include <iostream>

int main(){

	//Non const reference 
	std::cout << std::endl;
	std::cout << "Non const reference" << std::endl;
	int age {27};
	int& ref_age{age};
	const int& ref_age_const{age};

	std::cout << "age: " << age << std::endl;
	std::cout << "ref_age: " << ref_age << std::endl;
	std::cout << "ref_age_const: " << ref_age_const << std::endl;

	//Can modify original variable through reference

	std::cout << std::endl;
	std::cout << "Modify original variable through non-const reference" << std::endl;

	ref_age ++; //Modify through non-const reference

	std::cout << "age: " << age << std::endl;
	std::cout << "ref_age: " << ref_age << std::endl;
	std::cout << "ref_age_const: " << ref_age_const << std::endl;

 
	/* This would have error
	std::cout << std::endl;
	std::cout << "Modify original variable through const reference" << std::endl;

	ref_age_const ++; //Modify through const reference

	std::cout << "age: " << age << std::endl;
	std::cout << "ref_age: " << ref_age << std::endl;
	std::cout << "ref_age_const: " << ref_age_const << std::endl;
	*/

	//Simulating reference behavior with pointers
	const int * const p_age_const{&age};

	// *p_age_const = 30; //Complier Error

	std::cout << std::endl;
	std::cout << "p_age_const: " << p_age_const << std::endl;
	std::cout << "*p_age_const: " << *p_age_const << std::endl;    

	return 0;
}
