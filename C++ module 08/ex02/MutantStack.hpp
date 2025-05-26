#pragma once
#include <iostream>
#include <stack>

template <typename T>
class MutantStack: public std::stack<T>{
    public:
    typedef typename std::deque<T>::iterator iterator;
    MutantStack(){}
    MutantStack(const MutantStack &other){}
    MutantStack &operator=(const MutantStack &other){
        if (this != &other)
            std::stack<T>::operator=(other);
        return *this;
    }
    ~MutantStack(){}

    iterator begin(){
        return this->c.begin();
    }

    iterator end(){
        return this->c.end();
    }
};