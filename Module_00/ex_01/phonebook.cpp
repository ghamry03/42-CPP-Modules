#include "phonebook.hpp"

Phonebook::Phonebook  ( void ) {
	this->_count = 0;
	std::cout << "Salmo 3lyko, Welcome to Phonebook" << std::endl;
	return ;
}

Phonebook::~Phonebook ( void ) {
	std::cout << "Leaving Phonebook, w 3lykom el salam" << std::endl;
	return ;
}

void	Phonebook::add_contact( void ) {
	std::string		input;

/*	std::cout << "hmm add_contact" << std::endl;
	std::cout << "First Name: "; 
	std::cin >> input;
	this->_contacts[_count].set_firstName(input);
	std::cout << "Last Name: ";
	std::cin >> input;
	this->_contacts[_count].set_lastName(input);
	std::cout << "Nickname: ";
	std::cin >> input;
	this->_contacts[_count].set_nickname(input);
*/	//this->_count++;
	return ;
}

void	Phonebook::search_contact( void ) {
//	for (int i = 0; i < this->_count; i++) {
/*		std::cout << "------------------------";
		std::cout << "first name: " << this->_contacts[i].get_firstName() << std::endl;
		std::cout << "last name" << this->_contacts[i].get_lastName() << std::endl;
		std::cout << "nickname" << this->_contacts[i].get_nickname() << std::endl;
*///	}
	std::cout << "------------------------";
	return ;
}
