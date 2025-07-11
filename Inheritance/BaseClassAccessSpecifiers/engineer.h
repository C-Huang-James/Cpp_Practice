#ifndef ENGINEER_H
#define ENGINEER_H
#include "person.h"

// Engineer is doing private inheritance
// When use private inheritance, the public and protected members of the base class become private members of the derived class, respectively.
// The private members of the base class are inaccessible to the derived class.
class Engineer : private Person
{
friend std::ostream& operator<<(std::ostream& out , const Engineer& operand);
public:
    Engineer();
    ~Engineer();
    
    void build_something(){
        m_full_name = "John Snow"; // OK
        m_age = 23; // OK
        //m_address = "897-78-723"; Compiler error
    }
    
private : 
    int contract_count{0};
};

#endif // ENGINEER_H