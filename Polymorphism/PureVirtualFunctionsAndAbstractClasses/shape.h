#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <string>
#include <string_view>

class Shape 
{
    protected:
        Shape() = default;
        Shape(std::string_view description);

    public:
        virtual ~Shape() = default; // If destructor is not public, you won't be
                                    // able to delete base_ptrs. SHOW THIS TO STUDENTS

        // Pure virtual functions to be implemented by derived classes        
        virtual double perimeter() const = 0;
        virtual double surface() const = 0;
        // Once there's a virtual function in the base class
        // The base class automatically becomes a abstract class

    private:
        std::string m_description; // Description of the shape


};



#endif// SHAPE_H