#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal *hayawan = new WrongAnimal();
    const WrongAnimal *machiMoch = new WrongCat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << machiMoch->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    machiMoch->makeSound();
    hayawan->makeSound();

    delete j;
    delete i;
    delete meta;
    return 0;
    // Animal test;
    // test("name");
}