#include <iostream>
#include "person.h"
#include "player.h"
#include "nurse.h"
#include "engineer.h"

int main(){

    Person person1{"John Doe", 30, "1234 Main Street"};
    std::cout << person1 << std::endl;

    std::cout << "----------------------" << std::endl;

    Player player1;
    player1.m_full_name = "John Snow";
    // player1.m_age = 55; // age is protected from Person
    // player1.m_address = "DSAKFD; // address is private from Person
    std::cout << "address : " << player1.get_address() << std::endl;
    std::cout << player1 << std::endl;

    std::cout << "----------------------" << std::endl;

    Nurse nurse1;
    // nurse1.m_full_name = "John Snow"; // full_name is protected from Nurse
    // std::cout << "address : " << nurse1.get_address() << std::endl; // address is protected from Nurse
    std::cout << nurse1 << std::endl;

    std::cout << "----------------------" << std::endl;

    Engineer engineer1;
    std::cout << engineer1 << std::endl;



    return 0;
}