#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
    private:
        virtual std::string _getSound( void ) const;

    protected:
        std::string _type;

    public:
        Animal( void );
        Animal( std::string type );
        ~Animal( void );
        Animal( Animal & copy );
        Animal & operator=( Animal const & copy );

        std::string getType( void ) const;

        void makeSound( void ) const;

};

#endif

