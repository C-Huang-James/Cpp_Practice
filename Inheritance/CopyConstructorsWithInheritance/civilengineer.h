#ifndef CIVIL_ENGINEER_H
#define CIVIL_ENGINEER_H

#include "engineer.h"
// Eventhough we are doing public inheritance from Engineer
// Since the Engineer is doing private inheritance from Person
// We can't access the Person's members in CivilEngineer
class CivilEngineer : public Engineer
{
    friend std::ostream& operator<<(std::ostream&, const CivilEngineer& operand);
    public:
        CivilEngineer();
        CivilEngineer(std::string_view fullname,int age,
            std::string_view address,int contract_count_param,std::string speciality);
        CivilEngineer(const CivilEngineer& source);
        ~CivilEngineer() ;
        
        void build_road(){
            //get_full_name(); // Compiler error
            ///m_full_name = "Daniel Gray"; //Compiler error
            //m_age = 45; // Compiler error

            add(2,3); // OK
            add(2,3,4); // OK
            // do_something(); // Complier error since Engineer doesn't resurrect this function
        }
        
    private : 
        std::string m_speciality{"None"};

};

#endif // CIVIL_ENGINEER_H