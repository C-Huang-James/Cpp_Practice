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
    ~CivilEngineer() ;
    
    void build_road(){
        //get_full_name(); // Compiler error
        ///m_full_name = "Daniel Gray"; //Compiler error
        //m_age = 45; // Compiler error
    }
	
private : 
    std::string m_speciality{"None"};

};

#endif // CIVIL_ENGINEER_H