#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
    private:
        int                 _rawBits;
        static const int    _bitsNumber;

    public:
        Fixed( void );
        ~Fixed( void );
        Fixed( Fixed& copy );
        Fixed& operator=( Fixed const& copy );

        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
};

#endif
