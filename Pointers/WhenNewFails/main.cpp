#include <iostream>

int main(){
    
	// int *data = new int[1000000000000000000000];

	/*
	for(size_t i{0}; i < 10000000 ; ++i){
		int *data = new int[1000000];
	}*/

	/*
	//exception 
	//std::nothrow

	for(size_t i{0} ; i<100; ++i){
	
		try{
			int *data = new int[100000000000000];
		}catch(std::exception &ex){
			std::cout << "Something went wrong : " << ex.what() << std::endl;
			
		}
	}
		*/
	
	//std::nothrow
	for(size_t i{0} ; i < 100; ++i){
		int * data = new(std::nothrow) int[100000000000000];
		if(data != nullptr){
			std::cout << "Data allocated" << std::endl;
		}else{
			std::cout << "Something went wrong" << std::endl;
		}
	}
	std::cout << "Program ending well" << std::endl;

	return 0;
}