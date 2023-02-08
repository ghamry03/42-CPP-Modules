#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string.h>
# include <limits>

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
		void		setFirstName( std::string name );
		void		setLastName( std::string name );
		void		setNickname( std::string name );
		void		setPhoneNumber (std::string number );
		void		setSecret( std::string secret );
		std::string	getFirstName( void ) const;
		std::string getLastName( void ) const;
		std::string getNickname( void ) const;
		std::string getPhoneNumber( void ) const;
		std::string getSecret( void ) const;
		void		getContactInfo( void ) const;
};

#endif


