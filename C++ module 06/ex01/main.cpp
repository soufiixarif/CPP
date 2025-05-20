#include "Serializer.hpp"

int main(){
    Data *ptr = new Data();
    ptr->i = 5;
    uintptr_t Ser;
    Data * Deser;

    Ser = Serializer::serialize(ptr);

    Deser = Serializer::deserialize(Ser);

    std::cout << "the value is: " << Deser->i << std::endl;


}