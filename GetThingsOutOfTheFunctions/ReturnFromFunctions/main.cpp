#include <iostream>
#include <string>

int sum(int a, int b){
	int result = a + b;
	std::cout << "In : &result(int) : " << &result << std::endl;
	return result; //Return by value
}

std::string add_strings(std::string str1, std::string str2){
	std::string result = str1 + str2;
	std::cout << "In : &result(string) : " << &result << std::endl;
	return result; 	// Optimized by the compiler, not return by value, 
					// but return by reference 
}

int main(){

	int a {34};
	int b {56};

	int result = sum(a, b);
	std::cout << "Out : &result(int) : " << &result << std::endl;
	std::cout << "Sum : " << result << std::endl;

	std::string str_result = add_strings(std::string("Hello"), std::string(" World"));
    std::cout << "Out : &str_result(string) : " << &str_result << std::endl;
	std::cout << "Concatenated String : " << str_result << std::endl;
    return 0;
}