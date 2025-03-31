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

        virtual void run() const override{
            std::cout << "Dog " << m_description << " is running" << std::endl;
        }

        virtual void stream_insert(std::ostream& out)const override{
            out << "Dog [description : " << m_description << ", fur_style : " << 
                   m_fur_style << "]";
        }
};


#endif // DOG_H