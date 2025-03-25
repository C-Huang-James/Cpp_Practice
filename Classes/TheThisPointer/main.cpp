#include <iostream>
#include <string_view>

class Dog{
    public : 
        Dog() = default;
        Dog(std::string_view name_param, std::string_view breed_param, int  age_param);
        ~Dog();

        void print_info(){
            std::cout << "Dog (" << this << ") : [name : " << name
             << ", breed : " << breed << ", age : " << *p_age << "]" << std::endl;
        }

        // Setters
        // Normal way setters
        /*
        void set_dog_name(std::string_view name){
            // name = name; // assign value to the value itself, doing nothing
            this->name = name;
        }

        void set_dog_breed(std::string_view breed){
            this->breed = breed;
        }

        void set_dog_age(int age){
            *(this->p_age) = age;
        }
        */

        // Chained calls using pointers
        /*
        Dog* set_dog_name(std::string_view name){
            this->name = name;
            return this;
        }

        Dog* set_dog_breed(std::string_view breed){
            this->breed = breed;
            return this;
        }

        Dog* set_dog_age(int age){
            *(this->p_age) = age;
            return this;
        }
            */

        // Chained calls using references
        Dog& set_dog_name(std::string_view name){
            this->name = name;
            return *this;
        }

        Dog& set_dog_breed(std::string_view breed){
            this->breed = breed;
            return *this;
        }

        Dog& set_dog_age(int age){
            *(this->p_age) = age;
            return *this;
        }


    private : 
        std::string name;
        std::string breed;
        int * p_age{nullptr};
};

Dog::Dog(std::string_view name_param, std::string_view breed_param, int age_param)
    {
        name = name_param, 
        breed = breed_param;
        p_age = new int;
        *p_age = age_param;
        // this is the pointer to the object
        std::cout << "Dog constructor called for " << name << " at " << this << std::endl;
    }

Dog::~Dog(){ // destructor always has no parameters
    delete p_age;
    std::cout << "Dog destructor called for " << name << " at " << this << std::endl;
}

int main(){

    Dog dog1("Tiger", "Bulldog", 5);
    std::cout << "Dog1 address: " << &dog1 << std::endl;
    dog1.print_info();

    // With the normal setters
    /*
    dog1.set_dog_name("Max");
    dog1.set_dog_breed("Poodle");
    dog1.set_dog_age(3);
    */

    // Chained calls using pointers
    // dog1.set_dog_name("Max")->set_dog_breed("Poodle")->set_dog_age(3);

    // Chained calls using references
    dog1.set_dog_name("Max").set_dog_breed("Poodle").set_dog_age(3);


    dog1.print_info();
    

    std::cout << "Done!" << std::endl;

    return 0;
}