#include <iostream>
//Can check in cctype

int main(){

	//Check if character is alphanumeric

	std::cout << std::endl;
	std::cout << "std::isalnum : " << std::isalnum('C') << std::endl;
	std::cout << "std::isalnum : " << std::isalnum('^') << std::endl;
	
	char input_char {'*'};

	if(std::isalnum(input_char)){
		std::cout << input_char << " is an alphanumeric character." << std::endl;
	}else{
		std::cout << input_char << " is not an alphanumeric character." << std::endl;
	}


	//Check if character is alphabetic
	std::cout << std::endl;
	std::cout << "std::isalpha : " << std::endl;
	std::cout << "C is alphabetic : " << std::isalpha('C') << std::endl;
	std::cout << "^ is alphabetic : " << std::isalpha('^') << std::endl;
	std::cout << "7 is alphabetic : " << std::isalpha('7') << std::endl;
	
	if(std::isalpha('e')){
		std::cout << "e is alphabetic " << std::endl;
	}else{
		std::cout << "e is not alphabetic " << std::endl;
	}
	

	//Check if a character is blank

	std::cout <<std::endl;
	std::cout << "std::isblank : " << std::endl;
	char message[]{"Hello there. How are you doing? The sun is shining."};
	std::cout << "message : " << message << std::endl;

	//Find and print blank index
	size_t blank_cout{};
	for(size_t i{0}; i < std::size(message); ++i){
		// std::cout << "Value : " << message[i] << std::endl;
		if(std::isblank(message[i])){
			std::cout << "Blank character found at index : " << i << std::endl;
			++blank_cout;
		}
	}
	std::cout << "Total blank characters found : " << blank_cout << std::endl;

	
	//Check if character is lowercase or uppercase
	std::cout << std::endl;
	std::cout << "std::islower and std::isupper : " << std::endl;
	std::cout << std::endl;

	char thought[] {"The C++ programming Language is one of the most used on the Planet"};
	size_t lower_count{};
	size_t upper_count{};

	//Print original string for ease of comparision on the terminal 
	std::cout << "Original string : " << thought << std::endl;

	for (auto character : thought){
		if(std::islower(character)){
			std::cout << " " << character;
			++lower_count;
		}else if(std::isupper(character)){
			++upper_count;
		}
	}
	std::cout << std::endl;
	std::cout << "Found " << lower_count << " lowercase characters." << std::endl;
	std::cout << "Found " << upper_count << " uppercase characters." << std::endl;
	
	
	//Check if a character is a digit
	std::cout << std::endl;
	std::cout << "std::isdigit : " << std::endl;

	char statement[] {"Mr Hamilton owns 221 cows. That's a lot of cows! The kid exclamed."};
	std::cout << "Original statement : " << statement << std::endl;

	size_t digit_count{};

	for(auto character : statement){
		if(std::isdigit(character)){
			std::cout << "Found digit : " << character << std::endl;
			++digit_count;
		}
	}
	std::cout << "Total digits found : " << digit_count << std::endl;
	

	//Turning a character to lowercase using the std::tolower function
	std::cout << std::endl;
	std::cout << "std::tolower and std::toupper: " << std::endl;
	char original_str[] {"Home. The feeling of belonging."};
	char dest_str[std::size(original_str)]{};

	//Turn this to uppercase. Change the array in place
	for(size_t i{}; i < std::size(original_str); ++i){
		dest_str[i] = std::toupper(original_str[i]);
	}
	
	std::cout << "Original string : " << original_str << std::endl;
	std::cout << "Uppercase string : " << dest_str << std::endl;
	
	//Turn this to lowercase. Change the array in place
	for(size_t i{}; i < std::size(original_str); ++i){
		dest_str[i] = std::tolower(original_str[i]);
	}
	std::cout << "Lowercase string : " << dest_str << std::endl;	

	return 0;
}
