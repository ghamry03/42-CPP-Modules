#include "Harl.hpp"

Harl::Harl( void ) {
	return ;
}

Harl::~Harl( void ) {
	return ;
}

void	Harl::_debug( void ) {
	std::cout << "[DEBUG]: ";
	std::cout << "love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-special-ketchup";
	std::cout << "burger. I really do!" << std::endl;
}

void	Harl::_info( void ) {
	std::cout << "[INFO]: ";
	std::cout << "I cannot believe adding extra bacon costs more money.";
	std::cout << "You didn’t put enough bacon in my burger! If you did, ";
	std::cout << "I wouldn’t be asking for more!" << std::endl;
}

void	Harl::_warning( void ) {
	std::cout << "[WARNING]: ";
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I’ve been coming for years whereas you started working";
	std::cout << " here since last month." << std::endl;
}

void	Harl::_error( void ) {
	std::cout << "[ERROR]: ";
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl;
}

void	Harl::complain( std::string level ) {
	void		(Harl::*f[4])(void) = { &Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error };
	std::string	levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	for ( int i = 0; i < 4; i++ ) {
		if ( !level.compare(levels[i]) ) {
			(this->*f[i])();
			break ;
		}
	}
}
