#ifndef CIRCLE_H
#define CIRCLE_H
#include "oval.h"

class Circle : public Oval
{
    public:
        Circle() = default;
        Circle(double radius, std::string_view description);
        ~Circle();

        void draw() const{
            std::cout << "Circle::draw() called. Drawing " << m_description <<  " with radius : " << get_x_rad() << std::endl;
        }
};

#endif