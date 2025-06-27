#pragma once 
#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <sys/time.h>
#include <algorithm>
#include <limits>
#include <sstream>
#include <exception>

class PmergeMe{
    private:
        std::vector<int> vec;
        std::deque<int> deq;
        std::vector<int> sorted;
        struct timeval vectorStart, vectorEnd;
        struct timeval dequeStart, dequeEnd;
        bool parsInputNstortDataVec(int ac, char **av);
        bool parsInputNstortDataDeq(int ac, char **av);
        void insertMergeVector();
        void insertMergeDeque();
        void displayOutput();
    public :
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        void sort(int ac, char **av);
        template <typename T>
        void print_containers(const T &container, const std::string &title){
            std::cout << "====================" << title << "====================" << std::endl;
            for(size_t i = 0; i < container.size(); i++)
                std::cout << container[i] << std::endl;
        };
};