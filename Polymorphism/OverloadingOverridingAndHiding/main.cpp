#include <iostream>
#include <memory>
#include "shape.h"
#include "oval.h"
#include "circle.h"

int main(){ 
    
    Circle circle1(7.2,"circle1");
    Oval oval1(13.3,1.2,"Oval1");

    oval1.draw();
    oval1.draw(24);
    oval1.draw(24,"red");

    circle1.draw();
    circle1.draw(24);
    circle1.draw(24,"red"); // because we override the draw function in the derived class, 
                            // the overload function in the base class is hidden
                            // So we need to override the overload function in the derived class
                            // to make it visible in the derived class

    Shape *shape_ptr = new Circle(5.0,"Circle1");
    // The circle object is also a shape object
    // So we can use the base class pointer to point to the derived class object
    // The draw() and draw(int color_depth) functions are overriden in the derived 
    // class and also declared in the base class
    // Therefore the base class pointer can access the derived class object
    // and call the derived class draw() function
    shape_ptr->draw(); 
    shape_ptr->draw(24);
    // However, the draw(int color_depth, std::string_view color) function
    // is not an override function of the base class
    // So the base class pointer cannot access this function
    // shape_ptr->draw(24, "red"); // compiler error


    return 0;
}

