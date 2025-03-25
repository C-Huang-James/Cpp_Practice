#include <iostream>
#include "person.h"
#include "engineer.h"
#include "civilengineer.h"

int main(){

    Engineer eng1;

    CivilEngineer ce1;

    std::cout << "Engineer 1 : " << eng1 << std::endl;
    std::cout << "Civil Engineer 1 : " << ce1 << std::endl;

    ce1.add(2,3);
    ce1.add(2,3,4);
    // ce1.get_address(); // Compiler error

    std::cout << "Done" << std::endl;

  
   
    return 0;
}