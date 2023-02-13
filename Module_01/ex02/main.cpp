#include <iostream>

int	main( void ) {
	std::string		string = "HI THIS BRAIN";
	std::string*	stringPtr = &string;
	std::string&	stringRef = string;

	std::cout << "string memory address:\t\t" << &string << std::endl;
	std::cout << "stringPtr memory address:\t" << stringPtr << std::endl;
	std::cout << "stringRef memory address:\t" << &stringRef << std::endl;

	std::cout << "string value:\t\t\t" << string << std::endl;
	std::cout << "stringPtr value:\t\t" << *stringPtr << std::endl;
	std::cout << "stringRef value:\t\t" << stringRef << std::endl;
}
