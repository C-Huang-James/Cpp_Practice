#include <iostream>
#include "person.h"
#include "engineer.h"

int main(){

	Engineer eng1;
	std::cout << "eng1 : " << eng1 << std::endl;

	std::cout << "-----------------------------------" << std::endl;

	Engineer eng2("Daniel Gray",23,"asdl;fkjdas;fkdas;fk");
	std::cout << "eng2 : " << eng2 << std::endl;

	std::cout << "-----------------------------------" << std::endl;

	Engineer eng3("John Snow", 35 ,"a12575sdl;fkjdas;fkdas;fk", 5);
	std::cout << "eng3 : " << eng3 << std::endl;

    return 0;
}