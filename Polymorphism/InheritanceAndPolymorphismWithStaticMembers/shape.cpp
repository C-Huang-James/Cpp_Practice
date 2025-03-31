#include "shape.h"

int Shape::m_count{0};

Shape::Shape(std::string_view description)
    : m_description(description)
{
    std::cout << "Shape constructor called for : " << m_description << std::endl;
    std::cout << "Shape m_cout ++"<< std::endl;
    ++m_count;
}

Shape::Shape()
    : Shape("NoDescription")
{
}

Shape::~Shape()
{
    std::cout << "Shape destructor called for : " << m_description << std::endl;
    std::cout << "Shape m_cout --"<< std::endl;
    --m_count;
}
