#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

int main(void) {
    std::srand(static_cast<unsigned int>(time(NULL)));
    for (int i = 0; i < 5; i++) {
        Base * randomType = generate();
        identify(randomType);
        identify(*randomType);
        delete randomType;
        std::cout << std::endl;
    }
}
