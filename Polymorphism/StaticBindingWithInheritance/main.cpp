#include <iostream>
#include "shape.h"
#include "oval.h"
#include "circle.h"

void draw_circle(const Circle &circle){
    circle.draw();
}

void draw_shape(const Shape &shape){
    shape.draw();
}

int main(){ 

    Shape shape1("Shape1");
    shape1.draw();

    Oval oval1(2.0, 3.5, "Oval1");
    oval1.draw();

    Circle circle1(3.3, "Circle1");
    circle1.draw();

    //Base pointers
    Shape * p_shape = &shape1;
    p_shape->draw();

    p_shape = &oval1;
    p_shape->draw();

    p_shape = &circle1;
    p_shape->draw();    // we want to get the circle draw function, 
                        // but we get the shape draw function instead

    //Base references
    Shape & r_shape = shape1;
    r_shape.draw();

    //Drawing shapes
    draw_circle(circle1);
    draw_shape(shape1);

    //Shapes stored in collections
    Circle circle_collection[]{circle1, Circle(10.0, "Circle2"), Circle(20.0, "Circle3")};
    Oval oval_collection[]{oval1, Oval(22.3, 51.1, "Oval2"), Oval(22.3, 51.1, "Oval3")};
    // More array as you have more shape types


    return 0;
}

