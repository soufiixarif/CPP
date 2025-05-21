#include <iostream>

template <typename T>
void iter(T *ptr, size_t len, void (*f)(T &)){
    if (ptr == NULL || f == NULL)
        return ;
    for (size_t i = 0; i < len; i++)
        f(ptr[i]);
}

template <typename T>
void iter(T *ptr, size_t len, void (*f)(const T &)){
    if (ptr == NULL || f == NULL)
        return ;
    for (size_t i = 0; i < len; i++)
        f(ptr[i]);
}