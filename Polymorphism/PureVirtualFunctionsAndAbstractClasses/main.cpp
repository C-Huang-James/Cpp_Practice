#include <iostream>
#include "circle.h"
#include "rectangle.h"

int main(){
   
   //Shape * shape_ptr = new Shape; // Compiler error
                                    // Shape is an abstract class, can't create object of it

    const Shape * shape_rect = new Rectangle(10,10,"rect1");
    double surface = shape_rect->surface();
    std::cout << "dynamic type of shape_rect : " << typeid(*shape_rect).name() << std::endl;
    std::cout << "The surface of shape rect is : " << surface << std::endl;


    std::cout << "--------------" << std::endl;

    const Shape * shape_circle = new Circle(10,"circle1");
    surface = shape_circle->surface();
    std::cout << "dynamic type of shape_circle : " << typeid(*shape_circle).name() << std::endl;
    std::cout << "The surface of the circle is : " << surface << std::endl;
    return 0;
}

// the typeid operator is used to get the dynamic type of the object pointed to by the pointer.
// The name() function returns a string representation of the type.
// If complie with gcc or clang, we will get a number like "6Circle" or "9Rectangle"
// The number represent the length of the class name, and the rest is the class name itself.
// If compile with MSVC, we will get a string like "class Circle" or "class Rectangle"