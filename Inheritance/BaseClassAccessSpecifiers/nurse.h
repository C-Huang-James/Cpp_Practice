#ifndef NURSE_H
#define NURSE_H

#include "person.h"

//Nurse will do protected inheritance
//When use protected inheritance, the public and protected members of the base class become protected members of the derived class, respectively.
//The private members of the base class are inaccessible to the derived class.
class Nurse : protected Person
{
	friend std::ostream& operator<<(std::ostream& , const Nurse& operand);
public:
	Nurse();
	~Nurse();
	
    void treat_unwell_person(){
        m_full_name = "John Snow"; // OK
        m_age = 23; // OK
        //m_address = "897-78-723"; Compiler error
    }
    
private : 
    int practice_certificate_id{123459};
};

#endif // NURSE_H