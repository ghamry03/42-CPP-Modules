#include <iostream>
#include "phonebook.hpp"

int	main(void) {
	std::string	input;
	Phonebook	phonebook;

	while (input.compare("EXIT")) {
		std::cout << "Enter a command: "; 
		std::getline(std::cin, input);
		if (!input.compare("ADD"))
			phonebook.addContact();
		else if (!input.compare("SEARCH"))
			phonebook.searchContact();
		else
			std::cout << "unvalid cmd, try using ADD - SEARCH - EXIT" << std::endl;
	}
}

