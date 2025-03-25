#ifndef PLAYER_H
#define PLAYER_H

#include "person.h"

// Player will do public inheritance from Person
// When use public inheritance, the public and protected members of the base class become public and protected members of the derived class, respectively.
// The private members of the base class are inaccessible to the derived class.
class Player : public Person 
{
    friend std::ostream& operator<<(std::ostream& out, const Player& player);
public:
    Player();
    ~Player();
    
    //See the access we have to inherited members from Person
    void play(){
        m_full_name = "John Snow"; // OK
        m_age = 55; // OK
        //m_address = "DSAKFD;ASKFJ;DKAS"; Compiler error, cause it's private

    }
private : 
    int m_career_start_year{0};
    double m_salary{0.0};
    int health_factor{0};// Let's say that it's 0~10

};

#endif // PLAYER_H