#include <iostream>
#include <memory>
#include "shape.h"
#include "oval.h"
#include "circle.h"

int main(){ 

    Circle circle1(7.2, "circle1");
    Oval oval1(4.1, 5.7, "oval1");
    Circle circle2(3.5, "circle2");
    Oval oval2(2.3, 4.5, "oval2");
    Circle circle3(5.5, "circle3");
    Oval oval3(3.3, 6.5, "oval3");
    
    /*
    Shape shapes1[] {circle1, oval1, circle2, oval2, circle3, oval3};

    for(Shape s : shapes1){
        std::cout << "Inside array, sizeof(shape) : " << sizeof(s) << std::endl;
        Shape *ptr = &s;
        ptr->draw();
        std::cout << std::endl;
    }*/

    //What if we store in references? Compiler error : references aren't left assignable
	//const Shape& shapes2[] {circle1,oval1,circle2,oval2,circle3,oval3};

    //Raw pointers
    /*
	Shape* shapes3[] {&circle1,&oval1,&circle2,&oval2,&circle3,&oval3};
	
	for (Shape* shape_ptr : shapes3){
		std::cout << "Inside array , sizeof(*shape_ptr) : " << sizeof(*shape_ptr) << std::endl;
		shape_ptr->draw();	
		std::cout << std::endl;
	}*/

    //Smart pointers

    std::shared_ptr<Circle> circle4 = std::make_shared<Circle>(7.2, "circle4");
    std::shared_ptr<Oval> oval4 = std::make_shared<Oval>(4.1, 5.7, "oval4");
    std::shared_ptr<Circle> circle5 = std::make_shared<Circle>(3.5, "circle5");
    std::shared_ptr<Oval> oval5 = std::make_shared<Oval>(2.3, 4.5, "oval5");

	std::shared_ptr<Shape> shapes4[] {circle4,oval4,circle5,oval5};
    for(auto& s : shapes4){
        s->draw();
    }
    

    return 0;
}

