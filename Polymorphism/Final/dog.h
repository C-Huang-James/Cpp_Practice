#ifndef DOG_H
#define DOG_H
#include "feline.h"

class Dog : public Feline
{
    public:
        Dog() = default;
        Dog(std::string_view fur_stle, std::string_view description);
        virtual ~Dog();

        virtual void bark() const{
            std::cout << "Dog::bark called : Woof!" << std::endl;
        }

        virtual void breathe() const override{
            std::cout << "Dog::breathe called for : " << m_description << std::endl;
        }

        // With final operator, 
        // this method cannot be overridden in derived classes (downstream class)
        void run() const override final{
            std::cout << "Dog " << m_description << " is running" << std::endl;
        }

};


#endif // DOG_H