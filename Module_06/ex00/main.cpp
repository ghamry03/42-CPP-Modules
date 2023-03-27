#include "ScalarConverter.hpp"

void    convertToAll(std::string input) {
    try {
        std::cout << "char:\t";
        std::cout << ScalarConverter::convertToChar(input) << std::endl;
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << "int:\t";
        std::cout << ScalarConverter::convertToInt(input) << std::endl;
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << "float:\t";
        std::cout << static_cast<float>(ScalarConverter::convertToFloat(input)) << "f" << std::endl;
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << "double:\t";
        std::cout << ScalarConverter::convertToDouble(input) << std::endl;
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
}

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "Invalid number of arguments" << std::endl;
        return (false);
    }
    convertToAll(av[1]);
}
