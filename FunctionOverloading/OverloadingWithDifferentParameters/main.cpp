#include <iostream>

int max (int a, int b){
    std::cout << "int overload called" << std::endl;
    return a > b ? a : b;
}
/*
//Can't overload on the return type. Compiler will give an error.
double max (int a, int b){
    return a > b ? a : b;
}
*/

// Need to change the parameters
double max (double a, double b){
    std::cout << "double overload called" << std::endl;
    return a > b ? a : b;
}

double max (int a, double b){
    std::cout << "(int, double) overload called" << std::endl;
    return a > b ? a : b;
}

double max (double a, int b){
    std::cout << "(double, int) overload called" << std::endl;
    return a > b ? a : b;
}

double max (double a, int b, int c){
    std::cout << "(double, int, int) overload called" << std::endl;
    return max(a, max(b,c));
}

/*
The key difference between std::string and std::string_view lies in how they manage 
    and store string data:

std::string
Ownership: std::string owns the string data it contains. It manages memory 
    allocation, deallocation, and copying.
Heap Allocation: The string data is typically stored on the heap, and 
    std::string manages this memory.
Modifiable: std::string allows modification of the string content.
Performance: Operations like copying or assigning a std::string involve 
    allocating and copying the string data, which can be expensive for large strings.

std::string_view
Non-Ownership: std::string_view is a lightweight, non-owning reference to a 
    string. It does not manage memory.
No Heap Allocation: It simply points to an existing string's memory (e.g., a 
    std::string or a C-style string) without copying the data.
Immutable: std::string_view is read-only. You cannot modify the string content through it.
Performance: Since it avoids copying and memory allocation, std::string_view is more 
    efficient for passing or referencing strings, especially large ones.

Use Cases
Use std::string when you need to own and modify the string data.
Use std::string_view when you only need to read or reference an existing string without 
    taking ownership.
*/
std::string_view max(std::string_view a, std::string_view b){
    std::cout << "(string_view,string_view) overload called" << std::endl;
    return a > b ? a : b;
}

int main(){

    int int1 = 5;
    int int2 = 7;

    double double1 = 5.5;
    double double2 = 7.7;

    std::string_view string1 = "Hello";
    std::string_view string2 = "World";

    auto result = max(double1, int1, int2);
   
    max(string1, string2);
    return 0;
}

