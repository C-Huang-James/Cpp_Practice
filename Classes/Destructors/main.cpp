#include <iostream>
#include <string_view>

class Dog{
    public : 
        Dog() = default;
        Dog(std::string_view name_param, std::string_view breed_param, int  age_param);
        ~Dog();

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
        std::cout << "Dog constructor called for " << name << std::endl;
    }

Dog::~Dog(){ // destructor always has no parameters
    delete p_age;
    std::cout << "Dog destructor called for " << name << std::endl;
}

void dog_generator(){
    Dog* p_dog = new Dog("Milo", "Poodle", 3);
    delete p_dog; // if we don't delete the object, the destructor will not be called
}

int main(){
    Dog my_dog("Toby", "Golden Retriever", 5);

    dog_generator();    

    std::cout << "Done!" << std::endl;
    return 0;
}