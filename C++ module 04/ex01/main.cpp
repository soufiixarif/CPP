#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
    Animal *arr[100];
    for (int i = 0; i < 100; i++){
        if(i >= 50)
            arr[i] = new Dog();
        else
            arr[i] = new Cat();
    }
    for (int i = 0; i < 100; i++)
        arr[i]->makeSound();
    for (int i = 0; i < 100; i++)
        delete arr[i];
    return 0;
}