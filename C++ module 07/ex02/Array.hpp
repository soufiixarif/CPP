#pragma once
#include <exception>
#include <iostream>

template <typename T> class Array{
    private:
        T *arr;
        size_t len;
    public:
        Array(){
            len = 0;
            arr = new T[len]();
        }

        Array(size_t n){
            if (n > 0){
                len = n;
                arr = new T[n]();
            }
            else
                arr = NULL;
        }

        Array &operator=(const Array &other){
            if (this == &other)
                return *this;
            if (arr)
                delete []arr;
            len = other.len;
            arr = new T[len]();
            for (size_t i = 0; i < len; i++)
                arr[i] = other.arr[i];
            return *this;
        }

        Array(const Array &other){
            len = other.len;
            arr = new T[len]();
            for (size_t i = 0; i < len; i++)
                arr[i] = other.arr[i];
        }

        ~Array(){
            delete[] arr;
        }

        const T & operator[](size_t i)const {
            if (i > len)
                throw outOfbounds();
            return arr[i];
        }

        T & operator[](size_t i){
            if (i > len)
                throw outOfbounds();
            return arr[i];
        }

        size_t size()const {
            return len;
        }

        class outOfbounds: public std::exception{
            public:
                const char *what() const throw(){
                    return "the index given is out of bounds!";
                }
        };
};