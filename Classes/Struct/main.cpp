#include <iostream>

// Members private by default
class Dog{
    public : 
        std::string m_name;
};

// Members public by default
struct Cat{
    std::string m_name;
};

struct Point{
    double x;
    double y;
};

void print_point(const Point& point){
    std::cout << "Point [ x: " << point.x << ", y : " << point.y << "]" << std::endl;
}

int main(){

    Dog dog;
    dog.m_name = "Dog";
    std::cout << "Dog name : " << dog.m_name << std::endl;

    Cat cat;
    cat.m_name = "Cat";
    std::cout << "Cat name : " << cat.m_name << std::endl;

    Point point;
    point.x = 1.0;
    point.y = 2.0;
    print_point(point);

    return 0;
}