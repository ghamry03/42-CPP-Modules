#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal {
    protected:
        std::string _type;

    public:
        AAnimal( void );
        AAnimal( std::string const & type );
        virtual ~AAnimal( void );
        AAnimal( AAnimal const & copy );
        AAnimal & operator=( AAnimal const & copy );

        std::string getType( void ) const;

        virtual void makeSound( void ) const = 0;
};

#endif

