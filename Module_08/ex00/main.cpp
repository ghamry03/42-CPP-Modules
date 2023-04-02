#include "easyfind.hpp"
#include <vector>

int main( void ) {
    {
        std::vector< int > num;

        srand( static_cast<unsigned int>( time(NULL)) );
        for ( int i = 0; i < 10; i++ )
            num.push_back( rand() % 10 );

        for ( std::vector< int >::iterator it = num.begin();  it != num.end(); it++ ) {
            std::cout << *it;
            if ( it != num.end() - 1 )
                std::cout << ", ";
        }

        std::cout << std::endl;

        try {
            std::cout << "looking for number 5" << std::endl;
            std::cout << "index: " << easyFind( num, 5 ) - num.begin() << std::endl;
        }
        catch ( std::exception & e ) {
            std::cout << e.what() << std::endl;
        }
    }
}
