#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"

class Phonebook {
	private:
		int		_count;
		Contact	_contacts[8];

	public:
		Phonebook( void );
		~Phonebook( void );
		void add_contact( void );
		void search_contact( void );
};

#endif
