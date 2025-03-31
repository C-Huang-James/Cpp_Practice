#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : public Shape
{
public:
    Circle() = default;
    Circle(double radius , std::string_view  description);
    virtual ~Circle()= default;
    
    // the override keyword is optional but recommended
    virtual double perimeter() const override{ 
        return (2 * PI * m_radius);
    }

    virtual double surface() const override{
        return PI * m_radius* m_radius;
    }

    // As a derived class of a abstract class
    // it is necessary to implement all the pure virtual functions of the base class
    // otherwise the derived class will also be an abstract class

    
private: 
    double m_radius{0.0};
    
    inline static double PI{3.14159265};
    // In C++17 and later, inline allows static member variables 
    // to be defined directly in the header file without requiring 
    // a separate definition in a .cpp file. 
    // This simplifies the code and avoids linker errors.
};

#endif // CIRCLE_H