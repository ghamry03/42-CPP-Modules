#include "phonebook.hpp"

Phonebook::Phonebook  ( void ) {
	this->_count = 0;
	std::cout << "Welcome to phonebook" << std::endl;
	return ;
}

Phonebook::~Phonebook ( void ) {
	std::cout << "Leaving Phonebook, Byee" << std::endl;
	return ;
}

std::string	Phonebook::_fixString( std::string str ) {
	int		len;

	len = str.length();
	if (len > 10) {
		str.resize(9);
		str.append(".");
	}
	else if (len < 10) {
		str.insert(0, 10 - len, ' ');
	}
	return (str);
}

void	Phonebook::_getAllContacts( void ) {
	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < this->_count; i++) {
		std::cout << "|" << "         " << i;
		std::cout << "|" << _fixString(this->_contacts[i].getFirstName());
		std::cout << "|" << _fixString(this->_contacts[i].getLastName());
		std::cout << "|" << _fixString(this->_contacts[i].getNickname()) << "|" << std::endl;
	}
	std::cout << "|----------|----------|----------|----------|" << std::endl;
}

void	Phonebook::_moveContactDown( void ) {
	for (int i = 7; i > 0; i--) {
		this->_contacts[i] = this->_contacts[i - 1];
	}
}

void	Phonebook::_setNewContact( void ) {
	std::string		input;

	std::cout << "First Name: "; 
	std::getline(std::cin, input);
	this->_contacts[0].setFirstName(input);
	std::cout << "Last Name: ";
	std::getline(std::cin, input);
	this->_contacts[0].setLastName(input);
	std::cout << "Nickname: ";
	std::getline(std::cin, input);
	this->_contacts[0].setNickname(input);
	std::cout << "Phone number: ";
	std::getline(std::cin, input);
	this->_contacts[0].setPhoneNumber(input);
	std::cout << "Darkest Secret: ";
	std::getline(std::cin, input);
	this->_contacts[0].setSecret(input);
}

void	Phonebook::_incCount( void ) {
	this->_count++;
	if (this->_count > 8)
		this->_count = 8;
}

void	Phonebook::addContact( void ) {
	_moveContactDown();
	_setNewContact();
	_incCount();
	return ;
}

void	Phonebook::searchContact( void ) {
	int		input;

	if (_count == 0)
		std::cout << "Phonebook doesn't have any contacts" << std::endl;
	else {
		_getAllContacts();
		std::cout << "Enter contact index: ";
		std::cin >> input;
		std::cout << std::endl;
		std::cin.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' ); 
		if (std::cin.fail() || input > this->_count - 1 || input < 0) {
			std::cin.clear();
			std::cout << "Invalidfindex" << std::endl;
		} else {
			this->_contacts[input].getContactInfo();
		}
	}
	return ;
}
