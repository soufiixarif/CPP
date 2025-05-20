#include "Serializer.hpp"

Serializer::Serializer(){};

Serializer &Serializer::operator=(const Serializer &other){
    (void)other;
    return *this;
}

Serializer::Serializer(const Serializer &other){*this = other;}

Serializer::~Serializer(){}

uintptr_t Serializer::serialize(Data* ptr){
    uintptr_t convert = reinterpret_cast<uintptr_t>(ptr);
    return convert;
}

Data* Serializer::deserialize(uintptr_t raw){
    Data *ptr = reinterpret_cast<Data *>(raw);
    return ptr;
}



