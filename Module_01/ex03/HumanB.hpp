#ifndef HUMAN_B
# define HUMAN_B

# include "Weapon.hpp"

class HumanB {
	private:
		std::string			_name;
		const std::string*	_weapon;

	public:
		HumanB( std::string name );
		HumanB( std::string name, const std::string& weapon );
		~HumanB( void );

		void	attack( void );
};

#endif
