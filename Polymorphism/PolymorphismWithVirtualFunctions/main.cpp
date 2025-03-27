#include <iostream>
#include "shape.h"
#include "oval.h"
#include "circle.h"

// virtual functions let compiler dynamically bind the function call to the correct function
// based on the type of the object at runtime

void draw_shape(const Shape &shape){
    shape.draw();
}

void draw_shape(Shape* s){
    s->draw();
}

int main(){ 

    Shape shape1("Shape1");
    // shape1.draw();

    Oval oval1(2.0, 3.5, "Oval1");
    // oval1.draw();

    Circle circle1(3.3, "Circle1");
    // circle1.draw();

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
    draw_shape(circle1);
    draw_shape(oval1);
    draw_shape(shape1);

    draw_shape(&circle1);
    draw_shape(&oval1);
    draw_shape(&shape1);

    //Raw pointers
    p_shape = &oval1;
    // p_shape->get_x_rad(); // Compile error, not in bass class and not virtual

    //Shapes stored in collections
    Shape* shape_collection[]{&shape1,&oval1,&circle1};
    
    for(Shape* s_ptr : shape_collection){
        s_ptr->draw();
    }


    return 0;
}

