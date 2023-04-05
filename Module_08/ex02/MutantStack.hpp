#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
#include <iterator>
# include <stack>

template< typename T >
class MutantStack : public std::stack< T > {
    private:

    public:
        typedef typename std::stack< T >::container_type::iterator iterator;
        typedef typename std::stack< T >::container_type::const_iterator const_iterator;

        iterator begin( void ) {
            return this->c.begin();
        };

        iterator end( void ) {
            return this->c.end();
        };

        const_iterator cbegin ( void ) const {
            return this->c.begin();
        };

        const_iterator cend( void ) const {
            return this->c.end();
        };
};

#endif

