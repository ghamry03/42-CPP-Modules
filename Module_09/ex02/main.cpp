#include "PmergeMe.hpp"

int main(int ac, char** av) {
    if (ac < 3) {
        std::cout << "Error" << std::endl;
        return (EXIT_FAILURE);
    }
    PmergeMe t(av);
    return (t.run() ?  EXIT_SUCCESS : EXIT_FAILURE);
}
