#include <iostream>
#include "BitcoinExchange.hpp"

int main(int ac, char** av) {
    if ( ac != 2 ) {
        std::cerr << "Invalid number of arguments" << std::endl;
        return (EXIT_FAILURE);
    }
    BitcoinExchange a;
    return (a.run(av[1]) ? EXIT_SUCCESS : EXIT_FAILURE);
}
