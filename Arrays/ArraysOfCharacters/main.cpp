#include <iostream>

int main(){
     //Declare array
     char message[5] {'H', 'e', 'l', 'l', 'o'};

     //Print out the array through looping
     std::cout << "message : ";
     for(auto c : message){
          std::cout << c;
     }
     std::cout << std::endl;
     std::cout << "size : " << std::size(message) << std::endl;

     //Can also modify elements of the char array

     std::cout << std::endl;
     std::cout << "Modify array data : " << std::endl;

     message[1] = 'a';

     //Print out the array
     std::cout << "message : ";
     for(auto c : message){
          std::cout << c;
     }

     std::cout << std::endl;

     char message2[] {'H', 'e', 'l', 'l', 'o', '\0'}; // '\0' is the null terminator, print nothing
     std::cout << "message2 : " << message2 << std::endl;
     std::cout << "size : " << std::size(message2) << std::endl;
     for(auto c : message2){
          std::cout << c;
     }

     std::cout << std::endl;

     char message3[6] {'H', 'e', 'l', 'l', 'o'}; // '\0' will be added automatically
     std::cout << "message3 : " << message3 << std::endl;
     std::cout << "size : " << std::size(message3) << std::endl;
     for(auto c : message3){
          std::cout << c;
     }

     /*
          Note that in C++, double quotes are used to represnet string literals, 
          while single quotes are used to represent character literals.
     */

     std::cout << std::endl;

     char message4 [] {"Hello"};
     std::cout << "message4 : " << message4 << std::endl;
     std::cout << "size : " << std::size(message4) << std::endl;

     //
     int numbers [] {1,2,3,4,5};
     std::cout << "numbers : " << numbers << std::endl;
     for (auto n : numbers){
          std::cout << n << " ";
     }
     

     return 0;
}