#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <iostream>
# include "AMateria.hpp"

class IMateriaSource {
    public:
        IMateriaSource( void );
        // ~IMateriaSource( void );
        IMateriaSource( IMateriaSource const & copy );
        IMateriaSource & operator=( IMateriaSource const & copy );
        virtual ~IMateriaSource(); 
        virtual void learnMateria( AMateria * m ) = 0;
        virtual AMateria* createMateria( std::string const & type ) = 0;
};

#endif
