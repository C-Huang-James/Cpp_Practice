#include <iostream>
#include <string>

int main(){
	std::string full_name;//Empty string
    std::string planet {"Earth. Where the sky is blue"};//Initialize with string literal
	std::string prefered_planet{planet};//Initialize with other existing string
    std::string message {"Hello there",7};	//Initialize with part of a string literal.
											//Contains hello
    std::string weird_message(4,'e');//Initialize with multiple copies of a char
									 // contains eeee
    std::string greeting{"Hello World"};
    std::string saying_hello{ greeting,6,5};//Initialize with part of an existing std::string
											// starting at index 6, taking 5 characters.
											//Will contain World.
	
	std::cout << "full_name : " << full_name << std::endl;
	std::cout << "planet : " << planet << std::endl;
	std::cout << "prefered_planet : " << prefered_planet << std::endl;
	std::cout << "message : " << message << std::endl;
	std::cout << "weird_message : " << weird_message << std::endl;
	std::cout << "greeting : " << greeting << std::endl;
	std::cout << "saying_hello : " << saying_hello << std::endl;

    //Changing std::string at runtime
    planet = "Earth. Where the sky is blue Earth. Where the sky is blue Earth. Where ";
    std::cout << "planet : " << planet << std::endl;
	std::cout << "Address of planet (pointer itself): " << &planet << std::endl;
    // Can't so this
	// std::cout << "Address of the string (pointed by planet): " << static_cast<const void*>(planet) << std::endl;


    //Use a raw array
    const char * planet1 {"Earth. Where the sky is blue Earth."};
	std::cout << "Address of planet1 (pointer itself):" << &planet1 << std::endl;
	std::cout << "Address of the string (pointed by planet1, before modify): " << static_cast<const void*>(planet1) << std::endl;
    planet1 = "Earth. Where the sky is blue Earth. Where the sky is blue Earth. Where ";
    std::cout << "planet1 : " << planet1 << std::endl;
	std::cout << "Address of the string (pointed by planet1, after modify): " << static_cast<const void*>(planet1) << std::endl;


	return 0;
}
