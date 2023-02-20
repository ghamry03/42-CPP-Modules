#include <iostream>

int main(void){
	std::string	input;

	std::cin >> input;
	std::cout << input;
	getline(std::cin, input, '\0');
	std::cout << input;
}
