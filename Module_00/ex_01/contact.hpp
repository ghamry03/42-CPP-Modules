#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string.h>

class Contact {
	private: 
		std::string _firstName;
		std::string	_lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _secret;

	public:
		Contact( void );
		~Contact( void );
		void		set_firstName( std::string name );
		void		set_lastName( std::string name );
		void		set_nickname( std::string name );
		void		set_phoneNumber (std::string number );
		void		set_secret( std::string secret );
		std::string	get_firstName( void ) const;
		std::string get_lastName( void ) const;
		std::string get_nickname( void ) const;
		std::string get_phoneNumber( void ) const;
		std::string get_secret( void ) const;
};

#endif


