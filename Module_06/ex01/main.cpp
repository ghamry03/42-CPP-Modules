#include "Serializer.hpp"

int main(void) {
    Data * hamada = new Data;
    hamada->id = 69;
    hamada->name = "hamood";

    std::cout << hamada->id;
}
