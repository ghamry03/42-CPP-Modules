#include "Serializer.hpp"

int main(void) {
    Data * hamada = new Data;
    hamada->id = 69;
    hamada->name = "hamood";
   
    std::cout << hamada->id;

    uintptr_t test = Serializer::serialize(hamada);
    std::cout << "what are u?" << test << std::endl;

    Data * hamdy = Serializer::deserialize(test);
    std::cout << "mr hamdy: " << hamdy->name << std::endl;
}
