#pragma once
#include <iostream>
#include <exception>
#include <vector>
#include <iterator>
#include <algorithm>

template <typename T>
int easyfind(T &arg, int n){
    typename T::iterator it = std::find(arg.begin(), arg.end(), n);
    if(it == arg.end())
        throw std::out_of_range("element not found");
    return *it;
}