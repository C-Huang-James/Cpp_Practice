#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <string_view>
#include <iostream>

class Animal
{
public:
    Animal() = default;
    Animal(std::string_view description);
    // With the virtual destructor, 
    // the derived class destructor will be called first
    virtual ~Animal(); 
    
    virtual void breathe()const{
        std::cout << "Animal::breathe called for : " << m_description << std::endl;
    }
    
protected: 
    std::string m_description;
};

#endif // ANIMAL_H