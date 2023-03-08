# include "Animal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"

int main(void)
{
    const Animal * meta = new Animal();
    const Animal * i = new Cat();
    const Animal * j = new Dog();

    std::cout << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << meta->getType() << " " << std::endl;

    std::cout << std::endl;

    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    std::cout << std::endl;

    delete meta;
    delete i;
    delete j;

    return 0;
}
