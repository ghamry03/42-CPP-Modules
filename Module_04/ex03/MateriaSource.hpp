#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
    private:
        int        _materialsCount;
        AMateria * _materials[4];

    public:
        MateriaSource( void );
        ~MateriaSource( void );
        MateriaSource( MateriaSource const & copy );
        MateriaSource & operator=( MateriaSource const & copy );

        void       learnMateria( AMateria * m );
        AMateria * createMateria( std::string const & type );
};

#endif
