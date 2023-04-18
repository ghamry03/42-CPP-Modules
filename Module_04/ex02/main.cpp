# include "Animal.hpp"
# include "AAnimal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"

int main(void)
{
    {
        const AAnimal* j = new Dog();
        const AAnimal* i = new Cat();
        i->makeSound();
        j->makeSound();
        delete j;
        delete i;
    }
    return 0;
}
