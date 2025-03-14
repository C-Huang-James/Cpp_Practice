#include <iostream>
#include <string>

int main(){

     int max{};

     int a{35};
     int b{200};

     std::cout << std::endl;
     /*
     std::cout << "using regular if " << std::endl;
     if(a>b){
          max=a;
     }else{
          max=b;
     }
     */ 

     max = (a > b)? a : b; // Tenary Operator

     std::cout << "max: " << max << std::endl;

     auto max1 = (a > b)? a:22.5f; // Tenary Operator

     std::cout << "max1: " << max1 << std::endl;

     return 0;
}