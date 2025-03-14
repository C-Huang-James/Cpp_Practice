#include <iostream>

int main(){
     /*
     for(unsigned int i = 0; i < 10; i++){
          std::cout << i << " I love C++" << std::endl;
     }
     std::cout << "Loop done!" << std::endl;
     */
     /*
     for(size_t i{0} ; i<10; ++i){
          std::cout << i << " I love C++" << std::endl;
     }
     std::cout << "Loop done!" << std::endl;
     */
     /*
     std::cout << "Size of size_t: " << sizeof(size_t) << std::endl;
     */


     //Scope of the iterator
     /*
          for(size_t i{0} ; i<10 ; ++i){
               std::cout << i << " I love C++" << std::endl;
          }
          std::cout << "Loop done!" << std::endl;
     */

     // Iterator declared outside the loop
     /*
     size_t i = 0; // Iterator defined outside

     for( ; i<10; ++i){
          std::cout << i << " I love C++" << std::endl;
     }
     std::cout << "Loop done!" << std::endl;
     std::cout << "i: " << i << std::endl;
     */


     // Don't hard code values : BAD!

     const size_t COUNT{100};

     for(size_t i{0} ; i<COUNT; ++i){
          std::cout << i << " I love C++" << std::endl;
     }
     std::cout << "Loop done!" << std::endl;
     

     return 0;
}