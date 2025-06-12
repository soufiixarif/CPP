#include "Serializer.hpp"

int main(){
    Data *ptr = new Data();
    ptr->i = 42;
    ptr->name = "soufiix";
    uintptr_t Ser;
    Data * Deser;

    Ser = Serializer::serialize(ptr);
    Deser = Serializer::deserialize(Ser);

    std::cout << "the value is: " << Deser->i << std::endl;
    std::cout << "the name  is: " << Deser->name << std::endl;

    delete ptr;
}