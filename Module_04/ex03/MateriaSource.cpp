#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) : _materialsCount(0) {
    std::cout << "MateriaSource default contructor is called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->_materials[i] = NULL;
}

MateriaSource::~MateriaSource( void ) {
    std::cout << "MateriaSource destructor is called" << std::endl;
    for (int i = 0; i < 4; i++)
        if (this->_materials[i])
            delete this->_materials[i];
}

MateriaSource::MateriaSource( MateriaSource const & copy ) : IMateriaSource(copy) {
    std::cout << "MateriaSource copy constructor is called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->_materials[i] = NULL;
    *this = copy;
}

MateriaSource & MateriaSource::operator=( MateriaSource const & copy ) {
    std::cout << "MateriaSource copy assignment operator is called" << std::endl;
    for (int i = 0; i < 4; i++)
        if (this->_materials[i])
            this->_materials[i] = copy._materials[i]->clone();
    this->_materialsCount = copy._materialsCount;
    return ( *this );
}

void    MateriaSource::learnMateria( AMateria * m ) {
    if (this->_materialsCount == 4) {
        std::cout << "MateriaSource reached the maximum number of elements"
            << std::endl;
    } else {
        std::cout << "MateriaSource learned a new material" << std::endl;
        for (int i = 0; i < 4; i++) {
            if (!this->_materials[i]) {
                this->_materials[i] = m;
                _materialsCount++;
                break ;
            }
        }
    }
}

AMateria * MateriaSource::createMateria( std::string const & type ) {
    for (int i = 0; i < 4; i++) {
        if (this->_materials[i] && this->_materials[i]->getType() == type)
            return (this->_materials[i]->clone());
    }
    std::cout << "Material " << type << "isn't found" << std::endl;
    return (NULL);
}
