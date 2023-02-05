#include "contact.hpp"

Contact::Contact( void ) {
	return ;
}

Contact::~Contact( void ) {
	return ;
}

void	Contact::set_firstName( std::string name ) {
	this->_firstName = name;
	return ;
}

void	Contact::set_lastName( std::string name ) {
	this->_lastName = name;
	return ;
}

void	Contact::set_nickname( std::string name ) {
	this->_nickname = name;
	return ;
}

void	Contact::set_phoneNumber( std::string number ) {
	this->_phoneNumber = number;
	return ;
}

void	Contact::set_secret( std::string secret ) {
	this->_secret = secret;
	return ;
}



