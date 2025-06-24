#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &other){*this = other;}

PmergeMe &PmergeMe::operator=(const PmergeMe &other){
    if (this != &other){
        this->vec = other.vec;
        this->deq = other.deq;
    }
    return *this;
}
PmergeMe::~PmergeMe(){}

bool PmergeMe::parsInputNstorData(int ac, char **av){

    for (int i = 1; i < ac; i++){
        std::stringstream ss(av[i]);
        int n;
        ss >> n;
        if (ss.fail())
            return false;
        else if (n < 0)
            return false;
        this->vec.push_back(n);
        this->deq.push_back(n);
    }
    return true;
}

void PmergeMe::insertMergeVector(){
    int strugller = -1;
    (void)strugller;
    bool odd = false;
    if (vec.size() % 2 != 0){
        strugller = *vec.end();
        odd = true;
    }
    std::vector<std::pair<int, int> > pairs;
    size_t len = vec.size();
    if (odd)
        len = vec.size() - 1;
    for (size_t i = 0; i < len; i+=2)
        pairs.push_back(std::pair<int, int>(vec[i], vec[i + 1]));
    
    
    // std::vector<std::pair<int, int> >::iterator it;
    // for (it = pairs.begin(); it != pairs.end(); ++it) {
    //     std::cout << "(" << it->first << ", " << it->second << ")" << std::endl;
    // }
    // std::cout << "strugller: " << strugller << std::endl;
}

void PmergeMe::sort(int ac, char **av){
    if (ac < 2)
        throw std::runtime_error("need more params");
    else{
        if (!parsInputNstorData(ac, av))
            throw std::runtime_error("ERROR");
    }
    insertMergeVector();
}

void PmergeMe::print_containers(){
    std::cout << "==============vector=======================\n";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << std::endl;
    std::cout << "==============deque========================\n";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << deq[i] << std::endl;
}

