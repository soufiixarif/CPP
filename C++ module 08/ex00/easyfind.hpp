#include <iostream>
#include <exception>
#include <vector>
#include <iterator>
#include <algorithm>

template <typename T>
int easyfind(T &arg, int n){
    typename T::iterator holder = std::find(arg.begin(), arg.end(), n);
    if(holder == arg.end())
        throw std::out_of_range("element not found");
    return *holder;
}