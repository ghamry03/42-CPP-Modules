# include "Animal.hpp"
# include "AAnimal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"

int main(void)
{
    {
        const AAnimal* j = new Dog();
        const AAnimal* i = new Cat();
        delete j;//should not create a leak
        delete i;
    }
    return 0;
}
