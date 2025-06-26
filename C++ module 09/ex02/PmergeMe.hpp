#pragma once 
#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <exception>

class PmergeMe{
    private:
        std::vector<int> vec;
        std::deque<int> deq;
        bool parsInputNstortData(int ac, char **av);
        void insertMergeVector();
    public :
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        void sort(int ac, char **av);
        void print_containers();
};