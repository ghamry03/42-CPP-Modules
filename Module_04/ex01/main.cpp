# include "Animal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"

int main(void)
{
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        i->makeSound();
        j->makeSound();
        delete j;
        delete i;
    }
    return 0;
}
