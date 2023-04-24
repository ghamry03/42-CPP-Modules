# include "Animal.hpp"
# include "AAnimal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"

int main(void)
{
    AAnimal * i = new Cat();
    AAnimal * j = new Dog();

    std::cout << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;

    *i = *j;
    std::cout << i->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << std::endl;

    i->makeSound();
    j->makeSound();
    std::cout << std::endl;

    delete i;
    delete j;
}
