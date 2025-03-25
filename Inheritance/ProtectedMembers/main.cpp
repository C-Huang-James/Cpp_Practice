#include <iostream>
#include "player.h"

int main(){

    Player p1("Basketball");
    std::cout << "player 1 : "<< p1 << std::endl; 

    p1.set_first_name("John");
    p1.set_last_name("Snow");
    // p1.first_name = "John"; // This will not work as first_name is protected
    std::cout << "player 1 : "<< p1 << std::endl; 

    Player p2("Football", "Arya", "Stark");
    std::cout << "player 2 : "<< p2 << std::endl;

    return 0;
}