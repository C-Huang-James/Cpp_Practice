#include "person.h"

Person::Person(){
}

Person::Person(std::string& first_name_param, std::string& last_name_param)
    : first_name(first_name_param), last_name(last_name_param)
{
}

// This function is an overloaded << operator for the Person class. 
// It allows you to output a Person object to an output stream (like std::cout) 
// in a custom format.
std::ostream& operator<<(std::ostream& out , const Person& person){
    out << "Person [" << person.first_name << " " << person.last_name << "]";
    return out;
}


Person::~Person()
{
}
