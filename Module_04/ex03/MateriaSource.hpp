#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
    private:
        int        _materiaCount;
        AMateria * _items[4];

    public:
        MateriaSource(void);
        ~MateriaSource(void);
        MateriaSource(const MateriaSource & copy);
        MateriaSource & operator=(const MateriaSource & copy);

        void       learnMateria( AMateria * m );
        AMateria * createMateria( std::string const & type );
};

#endif

