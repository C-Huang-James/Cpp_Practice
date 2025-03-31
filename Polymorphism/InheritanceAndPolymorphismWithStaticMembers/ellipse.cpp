#include "ellipse.h"

int Ellipse::m_count{0};

Ellipse::Ellipse(double x_radius, double y_radius,
                            std::string_view description)
    : Shape(description), m_x_radius(x_radius),
                          m_y_radius(y_radius)
{
    std::cout << "Ellipse constructor called for : " << m_description << std::endl;
    std::cout << "Ellipse m_cout ++"<< std::endl;
    ++m_count;
}

Ellipse::Ellipse()
    : Ellipse(0.0,0.0,"NoDescription")
{
    
}

Ellipse::~Ellipse()
{
    std::cout << "Ellipse destructor called for : " << m_description << std::endl;
    std::cout << "Ellipse m_cout --"<< std::endl;
    --m_count;
}
