#include <iostream>

class Base
{
    public:
        Base(){
            std::cout << "Base constructor called" << std::endl;
        }

        virtual ~Base(){
            std::cout << "Base destructor called" << std::endl;
        }

        virtual void setup(){
            std::cout << "Base::setup() called" << std::endl;
            m_value = 10;
        }

        virtual void cleanup(){
            std::cout << "Base::cleanup() called" << std::endl;
        }

        int get_value(){
            return m_value;
        }

    protected:
        int m_value;
};

class Derived : public Base
{
    public:
        Derived():Base()
        {
            std::cout << "Derived constructor called" << std::endl;
        }

        virtual ~Derived(){
            std::cout << "Derived destructor called" << std::endl;
        }
        
        virtual void setup() override{
            std::cout << "Derived::setup() called" << std::endl;
            m_value = 100;
        }

        virtual void cleanup() override{
            std::cout << "Derived::cleanup() called" << std::endl;
        }
};


int main(){

    Base * p_base = new Derived;

    // The proper way to call the setup function
    // We should prevent call the virtual function in the constructor and destructor
    p_base -> setup(); 

    auto value = p_base -> get_value();
    std::cout << "Value: " << value << std::endl;

    p_base -> cleanup();

    delete p_base; 
    // Calls Derived destructor first, then Base destructor
    // Destructor order: Derived -> Base

    return 0;
}