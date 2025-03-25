#include <iostream>
#include "cylinder.h"


int main(){

    Cylinder cylinder1; // Objects
    std::cout << "volume : " << cylinder1.volume() << std::endl;

    Cylinder cylinder2(5.0, 6.0); // Objects
    std::cout << "volume : " << cylinder2.volume() << std::endl;
    std::cout << "base radius : " << cylinder2.get_base_radius() << std::endl;
    std::cout << "height : " << cylinder2.get_height() << std::endl;

    cylinder2.set_base_radius(10.0);
    cylinder2.set_height(12.0);
    std::cout << "volume : " << cylinder2.volume() << std::endl;
    std::cout << "base radius : " << cylinder2.get_base_radius() << std::endl;
    std::cout << "height : " << cylinder2.get_height() << std::endl;


    return 0;
}