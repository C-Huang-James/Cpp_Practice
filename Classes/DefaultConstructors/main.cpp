#include <iostream>

const double PI {3.1415926535897932384626433832795};

class Cylinder {
    public :
        //Constructors, has to be public
        Cylinder() = default; // Default constructor
        Cylinder(double rad_param, double height_param){
            base_radius = rad_param;
            height = height_param;
        } // If this constructor is defined, the default constructor is not generated

        double volume(){
            return PI * base_radius * base_radius * height;
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

    return 0;
}