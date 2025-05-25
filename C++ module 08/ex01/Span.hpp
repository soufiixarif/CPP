#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

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

        int min();
        int max();

        void addNumber(int n);
        int shortestSpan();
        int longestSpan();

        void showVector(){
            for (it = vec.begin(); it != vec.end(); it++) {
                std::cout << *it << " ";
            }
            std::cout << std::endl;
        }
};