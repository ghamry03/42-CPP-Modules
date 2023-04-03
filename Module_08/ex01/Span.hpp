#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <exception>
# include <algorithm>
# include <iterator>

class Span {
    private:
        unsigned int        _max;
        std::vector< int > _nums;
        

    public:
        Span( void );
        Span( unsigned int max );
        ~Span( void );
        Span( const Span & copy );
        Span & operator=( const Span & copy );

        void    printSpan( void );
        void    addNumber( int num );
        int     shortestSpan( void );
        int     longestSpan( void );
        void    AddRandomNumbers( int num );
        void    AddIterNumbers( const std::vector< int >::iterator begin,
                                const std::vector< int >::iterator end );

        unsigned int max( void ) const;

        class MaxElementsException : public std::exception {
            const char * what( void ) const throw();
        };

        class NotEnoughElementsException: public std::exception {
            const char * what( void ) const throw();
        };
};

#endif
