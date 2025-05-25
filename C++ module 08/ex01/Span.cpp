#include "Span.hpp"

Span::Span():N(100){
}

Span & Span::operator=(const Span &other){
    if (this == &other)
        return *this;
    this->N = other.N;
    return *this;
}

Span::Span(const Span &other){*this = other;}


Span::~Span(){}

Span::Span(unsigned int N){this->N = N;}

int Span::min(){
    int min = INT_MAX;
    for(it = vec.begin(); it != vec.end(); it++){
        if (*it < min)
            min = *it;
    }
    return (min);
}

int Span::max(){
    int max = INT_MIN;
    for(it = vec.begin(); it != vec.end(); it++){
        if (*it > max)
            max = *it;
    }
    return (max);
}

void Span::addNumber(int n){
    if (vec.size() == this->N)
        throw std::out_of_range("the vectore is full");
    vec.push_back(n);
}

int Span::longestSpan(){
    if (vec.size() < 2)
        throw std::logic_error("size less than 2");
    return (max() - min());
}

int Span::shortestSpan(){
    if (vec.size() < 2)
        throw std::logic_error("size less than 2");
    std::sort(vec.begin(), vec.end());

    int shortest = max();
    for (int i = 1; i < (int)vec.size(); i++){
        int diff = vec[i] - vec[i - 1];
        if (diff < shortest)
            shortest = diff;
    }
    return shortest;
}