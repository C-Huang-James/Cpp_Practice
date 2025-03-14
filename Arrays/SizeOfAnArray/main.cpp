#include <iostream>

int main(){
     int scores[] {10,12,15,11,19,16,22,23,24};

     //Range based for loop
     for(auto score : scores){
          std::cout << score << std::endl;
     }

     //Can get the size with std::size
     std::cout << "scores size : " << std::size(scores) << std::endl;

     //Print data out
     for(size_t i{0}; i<std::size(scores) ; ++i){
          std::cout << "scores[" << i << "] = " << scores[i] << std::endl;
     }

     std::cout << "size of scores : " << sizeof(scores) << std::endl; //size of the array
     std::cout << "size of scores[0] : " << sizeof(scores[0]) << std::endl; //size of the first element
     std::cout << "size of scores / size of scores[0] : " << sizeof(scores) / sizeof(scores[0]) << std::endl; 

     size_t count {sizeof(scores)/ sizeof(scores[0])};

     std::cout << "Printing out array items : " << std::endl;
     for(size_t i{0}; i<count ; ++i){
          std::cout << "scores[" << i << "] = " << scores[i] << std::endl;
     }

     int scores2[] {10,12,15,11,19,16,22,23,24,25,26,27,28,29,30};
     std::cout << "Using plain old range based for loop " << std::endl;
     for(auto score : scores2){
          std::cout << "score : " << score << std::endl;
     }

     return 0;
}