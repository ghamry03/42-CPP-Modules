#include "contact.hpp"

Contact::Contact( void ) {
	return ;
}

Contact::~Contact( void ) {
	return ;
}

void	Contact::setFirstName( std::string name ) {
	this->_firstName = name;
	return ;
}

void	Contact::setLastName( std::string name ) {
	this->_lastName = name;
	return ;
}

void	Contact::setNickname( std::string name ) {
	this->_nickname = name;
	return ;
}

void	Contact::setPhoneNumber( std::string number ) {
	this->_phoneNumber = number;
	return ;
}

void	Contact::setSecret( std::string secret ) {
	this->_secret = secret;
	return ;
}

std::string		Contact::getFirstName( void ) const {
	return (this->_firstName);
}

std::string		Contact::getLastName( void ) const {
	return (this->_lastName);
}

std::string		Contact::getNickname( void ) const {
	return (this->_nickname);
}

std::string		Contact::getPhoneNumber( void ) const {
	return (this->_phoneNumber);
}

std::string		Contact::getSecret( void ) const {
	return (this->_secret);
}

void			Contact::getContactInfo( void ) const {
	std::cout << "First Name: " << this->getFirstName() << std::endl;
	std::cout << "Last Name: " << this->getLastName() << std::endl;
	std::cout << "Nickname: " << this->getNickname() << std::endl;
	std::cout << "Phone Number: " << this->getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << this->getSecret() << std::endl;
}
