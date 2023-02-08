#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"

class Phonebook {
	private:
		int			_count;
		Contact		_contacts[8];
		std::string	_fixString( std::string );
		void		_getAllContacts( void );
		void		_moveContactDown( void );
		void		_setNewContact( void );
		void 		_incCount( void );
		std::string	_getUserInput( void );

	public:
					Phonebook( void );
					~Phonebook( void );
		void	 	addContact( void );
		void		searchContact( void );
};

#endif
