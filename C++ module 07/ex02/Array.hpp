#pragma once

template <typename T> class Array{
    private:
        T *arr;
        unsigned int len;
    public:
        Array(){
            len = 0;
            arr = new[len];
        }
        Array(unsigned int n){
            len = n;
            arr = new[len];
        }
        Array(const Array &other);
        Array &operator=(const Array &other);
        ~Array();
};