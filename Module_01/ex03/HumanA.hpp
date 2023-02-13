#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include "Weapon.hpp"

class	HumanA {
	private:
		std::string				_name;
		const std::string&		_weapon;

	public:
		HumanA( std::string name, const std::string& weapon );
		~HumanA( void );

		void	attack( void );
};

#endif
