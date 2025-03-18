#include "person.h"

// double weight {}; // already declared in main file

struct Point
{
	double m_x;
	double m_y;
};


double add(double a, double b){
	return a + b;
}

int Person::person_count = 8;

Person::Person(const std::string &name, int age_param)
    : full_name{name}, age{age_param}
{
    person_count++;
}