#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {
    private:
        std::string * _ideas;

    public:
        Brain( void );
        ~Brain( void );
        Brain( Brain const & copy );
        Brain & operator=( Brain const & copy );

};

#endif

