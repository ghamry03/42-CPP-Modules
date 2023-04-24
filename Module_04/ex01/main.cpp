# include "Animal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"

int main(void)
{
    {
        Animal  *array[100];
        for ( int i = 0; i < 100; i++ ) {
            if ( i % 2 == 0 )
                array[i] = new Dog();
            else
                array[i] = new Cat();
        }

        for ( int i = 0; i < 100; i++ )
            array[i]->makeSound();

        for ( int i = 0; i < 100; i++ )
            delete array[i];
    }
    return 0;
}
