#include "person.h"
#include <iostream>

Person::Person(std::string_view fullname, int age,
    const std::string address) 
        : m_full_name{fullname}, m_age{age},
            m_address{address}
{
}

std::ostream& operator<<(std::ostream& out , const Person& person){
   out << "Person [Full name :" << person.get_full_name() <<
                      ", Age:" << person.get_age() <<
                      ", Address:" << person.get_address() << "]";
  return out;
}

void Person::do_something() const{
    std::cout << "Person is doing something" << std::endl;
}


std::string Person::get_full_name()const{
    return m_full_name;
}

int Person::get_age()const{
    return m_age;
}

std::string Person::get_address()const{
    return m_address;
}

int Person::add( int a, int b){
    return a + b;
} 

int Person::add( int a, int b, int c){
    return a + b + c;
}

Person::~Person()
{
}

