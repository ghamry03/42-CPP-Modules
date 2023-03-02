#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <fstream>
# include <cmath>

class Fixed {
    private:
        int                 _num;
        static const int    _bitsNum = 8;

    public:
        Fixed( void );
        Fixed( Fixed const& copy );
        Fixed( const int num );
        Fixed( const float num );
        ~Fixed( void );

        Fixed&          operator=( Fixed const& copy );
        Fixed           operator+( Fixed const& copy ) const;
        Fixed           operator-( Fixed const& copy ) const;
        Fixed           operator*( Fixed const& copy ) const;
        Fixed           operator/( Fixed const& copy ) const;
        bool            operator>( Fixed const& copy ) const;
        bool            operator<( Fixed const& copy ) const;
        bool            operator>=( Fixed const& copy ) const;
        bool            operator<=( Fixed const& copy ) const;
        bool            operator==( Fixed const& copy ) const;
        bool            operator!=( Fixed const& copy ) const;
        Fixed           operator++( void );
        Fixed           operator++( int num );
        Fixed           operator--( void );
        Fixed           operator--( int num );

        int             getNum( float raw );
        int             getRawBits( void ) const;
        void            setRawBits( int const raw );
        int             toInt( void ) const;
        float           toFloat( void ) const;
        static Fixed&          min( Fixed& a, Fixed& b );
        static const Fixed&    min( const Fixed& a, const Fixed& b );
        static Fixed&          max( Fixed& a, Fixed& b );
        static const Fixed&    max( const Fixed& a, const Fixed& b );
};

std::ostream&   operator<<( std::ostream& stream, Fixed const& fixed );

#endif
