#include <iostream>
#include "person.h"

//Variable 
double weight {};

double add(double a, double b); // not define yet

// For classes and structs, we can give them multiple definitions
// but have to be show up in the different translation unit
struct Point 
{
	double m_x{};
	double m_y{};
};


int main(){

	double result = add(1,5); // this works fine
	
	std::cout << weight << std::endl;
	std::cout << result << std::endl;

	Person p1("John Snow", 35);
	p1.print_info();

	return 0;
}

// For function, we can only have one definition
// double add(double a, double b){
// 	return a + b;
// }