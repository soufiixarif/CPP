#pragma once
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <exception>

class Span{
    private:
        unsigned int N;
        std::vector<int> vec;
        std::vector<int>::iterator it;
    public:
        Span();
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        Span(unsigned int N);

        void addNumber(int n);
        template<typename Iterator> void addNumber(Iterator begin, Iterator end){
            size_t distance = std::distance(begin, end);
            if (vec.size() + distance > N)
                throw std::overflow_error("Cannot add range: exceeds maximum size");
            vec.insert(vec.end(), begin, end);
        }
        int shortestSpan();
        int longestSpan();
};