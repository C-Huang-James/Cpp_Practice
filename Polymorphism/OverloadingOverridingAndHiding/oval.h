#ifndef OVAL_H
#define OVAL_H
#include "shape.h"
#include <string>
#include <string_view>

class Oval : public Shape
{
    public:
        Oval() = default;
        Oval(double x_radius, double y_radius,
             std::string_view description);
        ~Oval();
        
        
        virtual void draw() const override{
            std::cout << "Oval::draw() called. Drawing " << m_description <<  " with m_x_radius : " << m_x_radius << " and m_y_radius : " << m_y_radius << std::endl;
        }

        // If the function is overloaded in the bass class,
        // it wll be hidden by the derived class override function
        // Therefore we need to  override the overloaded function in the derived class
        // to make it visible in the derived class
        virtual void draw(int color_depth) const override{
            std::cout << "Oval::Drawing with color depth " << color_depth << std::endl;
        }

        // This overload function belongs to the derived class
        // and it is not an override function of the base class
        // So the base class object cannot access this function
        virtual void draw(int color_depth, std::string_view color) const{
            std::cout << "Oval::Drawing with color depth " << color_depth << " and color : "
            << color << std::endl;
        }
        
    
    protected:
        double get_x_rad() const{
            return m_x_radius;
        }
        double get_y_rad() const{
            return m_y_radius;
        }

    private:
        double m_x_radius{0.0};
        double m_y_radius{0.0};
};

#endif