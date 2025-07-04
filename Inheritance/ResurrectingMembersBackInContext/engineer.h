#ifndef ENGINEER_H
#define ENGINEER_H
#include "person.h"

//Engineer is doing private inheritance

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

        using Person::add; //resurrect the function from Person with public access

    protected :
        using Person::get_full_name; // resurrect functions from Person with protected access
        using Person::get_age;
        using Person::get_address;
        // using Person::m_address; // cannot resurrect private members

        int get_contract_count() const{
            return contract_count;
        }
    
    private : 
        int contract_count{0};
};

#endif // ENGINEER_H