#include <iostream>
#include "cylinder.h"


int main(){

    // Stack object: . notation
    Cylinder c1(3, 4);
    std::cout << "volume of c1: " << c1.volume() << std::endl;

    // Heap object : . dereference  and . notation
    //               . -> notation
    Cylinder* c2 = new Cylinder(3, 4); // Create an object on heap
    std::cout << "volume of c2 (wit dereferencing) : " << (*c2).volume() << std::endl;
    std::cout << "volume of c2 (with arrow) : " << c2->volume() << std::endl;
    delete c2; // Delete the object from heap

    Cylinder* p_c3 = &c1; // Create a pointer to the stack object
    std::cout << "volume of c3 (with arrow) : " << p_c3->volume() << std::endl;
    std::cout << "base radius of c3 (with arrow) : " << p_c3->get_base_radius() << std::endl;
    return 0;
}