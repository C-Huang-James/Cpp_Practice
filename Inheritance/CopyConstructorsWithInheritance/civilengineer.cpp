#include "person.h"
#include "engineer.h"
#include "civilengineer.h"
#include <iostream>

CivilEngineer::CivilEngineer()
{
    std::cout << "Default constructor for CivilEngineer called..." << std::endl;
}

CivilEngineer::CivilEngineer(std::string_view fullname,int age,
    std::string_view address,int contract_count_param,std::string speciality):
    Engineer(fullname,age,address,contract_count_param), m_speciality{speciality}
{
    std::cout << "Custom constructor for CivilEngineer called..." << std::endl;
}

CivilEngineer::CivilEngineer(const CivilEngineer& source) :
    Engineer(source), m_speciality{source.m_speciality}
{
    std::cout << "Copy constructor for CivilEngineer called..." << std::endl;
}

std::ostream& operator<<(std::ostream& out, const CivilEngineer& operand){
     out << "CivilEngineer [Full name : " << operand.get_full_name() <<
                    ", age : " << operand.get_age() << 
                    ", address : " << operand.get_address() <<
                    ", contract_count : " << operand.get_contract_count() <<
                    ", speciality : " << operand.m_speciality << "]";
    return out;  
}


CivilEngineer::~CivilEngineer()
{
}