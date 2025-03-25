#include <iostream>

const double PI {3.1415926535897932384626433832795};

class Cylinder {

    public :
        //Constructors
        Cylinder() = default; 
        Cylinder(double rad_param, double height_param){
            base_radius = rad_param;
            height = height_param;
        } 

        //Funtcions (methods)
        double volume(){
            return PI * base_radius * base_radius * height;
        }

        //Setter and getter methods
        double get_base_radius() const {
            return base_radius;
        }
        double get_height() const {
            return height;
        }
        void set_base_radius(double rad_param){
            base_radius = rad_param;
        }
        void set_height(double height_param){
            height = height_param;
        }

    private :
        // Member vatiables
        double base_radius {1.0};
        double height {1.0};
};

int main(){

    Cylinder cylinder1; // Objects
    std::cout << "volume : " << cylinder1.volume() << std::endl;

    Cylinder cylinder2(5.0, 6.0); // Objects
    std::cout << "volume : " << cylinder2.volume() << std::endl;
    std::cout << "base radius : " << cylinder2.get_base_radius() << std::endl;
    std::cout << "height : " << cylinder2.get_height() << std::endl;

    cylinder2.set_base_radius(10.0);
    cylinder2.set_height(12.0);
    std::cout << "volume : " << cylinder2.volume() << std::endl;
    std::cout << "base radius : " << cylinder2.get_base_radius() << std::endl;
    std::cout << "height : " << cylinder2.get_height() << std::endl;


    return 0;
}