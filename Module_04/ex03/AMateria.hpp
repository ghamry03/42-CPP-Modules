#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

class ICharacter;

class AMateria {
    protected:
        std::string  _type;

    public:
        AMateria( void );
        AMateria( std::string const & type );
        ~AMateria( void );
        AMateria( AMateria const & copy );
        AMateria & operator=( AMateria const & copy );

        std::string const & getType( void ) const;

        virtual void       use(ICharacter & target);
        virtual AMateria * clone( void ) const = 0;
};

#endif
