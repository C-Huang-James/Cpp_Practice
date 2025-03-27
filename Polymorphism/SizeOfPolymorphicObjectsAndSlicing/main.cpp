#include <iostream>
#include "shape.h"
#include "oval.h"
#include "circle.h"

int main(){ 

    //Comparing object sizes
    std::cout << "sizeof(Shape) : " << sizeof(Shape) << std::endl; // dynamic : 40, static : 32
    std::cout << "sizeof(Oval) : " << sizeof(Oval) << std::endl; // dynamic : 56, static : 48
    std::cout << "sizeof(Circle) : " << sizeof(Circle) << std::endl; // dynamic : 56, static : 48
    // Polymorphism is not free. It comes with a cost. The cost is the size of the object.


    // Slicing
    Circle circle1{10, "Circle"};
    Shape shape1 = circle1;
    shape1.draw(); // Shape::draw() called. Drawing Circle
    std::cout << "Size of circle1 : " << sizeof(circle1) << std::endl;
    std::cout << "Size of shape1 : " << sizeof(shape1) << std::endl;

    return 0;
}

