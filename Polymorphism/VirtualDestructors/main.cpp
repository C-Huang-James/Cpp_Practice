#include <iostream>
#include "dog.h"

int main(){

   Animal * p_animal = new Dog;

   delete p_animal;

   Dog dog("short", "dog");
  
    return 0;
}