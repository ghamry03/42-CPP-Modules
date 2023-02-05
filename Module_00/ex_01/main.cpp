#include <iostream>
#include "phonebook.hpp"

int	main(void) {
	std::string	input;
	Phonebook	phonebook;

	while (input.compare("END")) {
		std::cin >> input;
		if (!input.compare("ADD"))
			phonebook.add_contact();
		else if (!input.compare("SEARCH"))
			phonebook.search_contact();
		else
			std::cout << "unvalid cmd, try using ADD - SEARCH - EXIT" << std::endl;
	}
}

