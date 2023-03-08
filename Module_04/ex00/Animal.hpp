#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
    protected:
        std::string _type;

    public:
        Animal( void );
        Animal( std::string type );
        virtual ~Animal( void );
        Animal( Animal & copy );
        Animal & operator=( Animal const & copy );

        std::string getType( void ) const;

        virtual void makeSound( void ) const;

};

#endif

