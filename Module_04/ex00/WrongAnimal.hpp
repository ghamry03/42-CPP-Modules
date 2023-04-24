#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal {
    protected:
        std::string _type;
        WrongAnimal( std::string const & type );

    public:
        WrongAnimal( void );
        virtual ~WrongAnimal( void );
        WrongAnimal( WrongAnimal const & copy );
        WrongAnimal & operator=( WrongAnimal const & copy );

        std::string getType( void ) const;

        void makeSound( void ) const;
};

#endif

