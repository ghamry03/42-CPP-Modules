#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal {
    protected:
        std::string _type;

    public:
        WrongAnimal( void );
        WrongAnimal( std::string const & type );
        virtual ~WrongAnimal( void );
        WrongAnimal( WrongAnimal const & copy );
        WrongAnimal & operator=( WrongAnimal const & copy );

        std::string getType( void ) const;

        void makeSound( void ) const;
};

#endif

