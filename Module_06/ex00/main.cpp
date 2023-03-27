#include "ScalarConverter.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "Invalid number of arguments" << std::endl;
        return (false);
    }
    return (ScalarConverter::printAllConversions(av[1]));
}
