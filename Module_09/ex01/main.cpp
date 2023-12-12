#include "RPN.hpp"

int main(int ac, char** av) {
    if (ac != 2) {
        std::cerr << "Error" << std::endl;
        return (EXIT_FAILURE);
    }
    RPN a;
    return (a.calculate(av[1]) ? EXIT_SUCCESS : EXIT_FAILURE);
}
