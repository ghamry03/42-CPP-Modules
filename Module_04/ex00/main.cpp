# include "Animal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"
# include "WrongCat.hpp"

int main(void)
{
    const Animal * meta = new Animal();
    const Animal * i = new Cat();
    const Animal * j = new Dog();
    const WrongAnimal * x = new WrongCat();

    std::cout << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << x->getType() << " " << std::endl;
    std::cout << meta->getType() << " " << std::endl;

    std::cout << std::endl;

    i->makeSound(); //will output the cat sound!
    j->makeSound();
    x->makeSound();
    meta->makeSound();
    std::cout << std::endl;

    delete meta;
    delete i;
    delete j;

    return 0;
}
