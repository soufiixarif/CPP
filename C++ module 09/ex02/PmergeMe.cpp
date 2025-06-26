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

bool PmergeMe::parsInputNstortData(int ac, char **av){

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

void sortpairs(std::vector<std::pair<int, int> > &pairs){
    std::vector<std::pair<int, int> >::iterator it;
    for(it = pairs.begin(); it != pairs.end(); it++){
        if (it->first < it->second)
            std::swap(it->first, it->second);
    }
}

void makeMainPend(std::vector<std::pair<int, int> > &pairs, std::vector<int> &main, std::vector<int> &pend){
    std::vector<std::pair<int, int> >::iterator it;
    for(it = pairs.begin(); it != pairs.end(); it++){
        if (it == pairs.begin()){
            main.push_back(it->second);
            main.push_back(it->first);
        }
        else{
            main.push_back(it->first);
            pend.push_back(it->second);
        }       
    }
}

void    merge(std::vector<std::pair<int,int> > &pairs, int l, int m, int r){
    int len1, len2;
    len1 = m - l + 1;
    len2 = r - m;
    std::vector<std::pair<int, int> > vecL(len1), vecR(len2);

    for (int i = 0; i < len1; i++)
        vecL[i] = pairs[l + i]; 
    for (int i = 0; i < len2; i++)
        vecR[i] = pairs[m + 1 + i];
    
    int i = 0,j = 0,k = l;
    while(i < len1 && j < len2){
        if (vecL[i].first <= vecR[j].first){
            pairs[k] = vecL[i];
            i++;
        }
        else{
            pairs[k] = vecR[j];
            j++;
        }
        k++;
    }

    while (i < len1){
        pairs[k] = vecL[i];
        i++,k++;
    }

    while(j < len2){
        pairs[k] = vecR[j];
        j++, k++;
    }
}

void recursion_sort(std::vector<std::pair<int,int> > &pairs, int l, int r){
    if (l < r){
        int m = (l + r) / 2;
        recursion_sort(pairs, l, m);
        recursion_sort(pairs, m + 1, r);
        merge(pairs, l, m, r);
    }
}

std::vector<int> jacobsthalgenerator(int pendSize){//to change it later
    std::vector<int> seqIndex;

    if (pendSize < 0)
        return seqIndex;

    seqIndex.push_back(0);  // Always start with 0

    std::vector<int> jacob;
    jacob.push_back(0);
    jacob.push_back(1);

    // Generate all Jacobsthal numbers ≤ pendSize
    while (true) {
        int next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
        if (next > pendSize)
            break;
        jacob.push_back(next);
    }

    // Add Jacobsthal-based insertion order
    for (size_t i = 1; i < jacob.size(); ++i) {
        seqIndex.push_back(jacob[i]);

        // Insert the gap between jacob[i] and jacob[i+1] in reverse
        int from = jacob[i] - 1;
        int to = jacob[i - 1];
        for (int k = from; k > to; --k) {
            seqIndex.push_back(k);
        }
    }

    // Add remaining tail values if any
    int lastJacob = jacob.back();
    for (int i = lastJacob + 1; i <= pendSize; ++i) {
        seqIndex.push_back(i);
    }

    return seqIndex;
}

void PmergeMe::insertMergeVector(){
    int strugller = -1;
    (void)strugller;
    bool odd = false;
    if (vec.size() % 2 != 0){
        strugller = *(vec.end() - 1);
        odd = true;
    }
    std::vector<std::pair<int, int> > pairs;
    size_t len = vec.size();
    if (odd)
        len = vec.size() - 1;
    for (size_t i = 0; i < len; i+=2)
        pairs.push_back(std::pair<int, int>(vec[i], vec[i + 1]));

    sortpairs(pairs);

    recursion_sort(pairs, 0, pairs.size() - 1);

    std::vector<int> main;
    std::vector<int> pend;

    makeMainPend(pairs, main, pend);

    std::vector<int> JacobIndex = jacobsthalgenerator(pend.size());

    for (int i = 0; i < (int)JacobIndex.size(); i++)
        std::cout << JacobIndex[i] << std::endl;
    // std::cout << "===================befor=========================\n";
    // std::vector<std::pair<int, int> >::iterator it;
    // for (it = pairs.begin(); it != pairs.end(); ++it) {
    //     std::cout << "(" << it->first << ", " << it->second << ")" << std::endl;
    // }
    // std::cout << "strugller: " << strugller << std::endl;

    // std::cout << "===================after=========================\n";
    // // std::vector<std::pair<int, int> >::iterator it;
    // for (it = pairs.begin(); it != pairs.end(); ++it) {
    //     std::cout << "(" << it->first << ", " << it->second << ")" << std::endl;
    // }
    // std::cout << "strugller: " << strugller << std::endl;
    // std::cout << "===================main=========================\n";
    // std::vector<int>::iterator it;
    // for (it = main.begin(); it != main.end(); ++it) {
    //     std::cout << "(" << *it << ")" << std::endl;
    // }
    // std::cout << "===================pend=========================\n";
    // for (it = pend.begin(); it != pend.end(); ++it) {
    //     std::cout << "(" << *it << ")" << std::endl;
    // }
    
}

void PmergeMe::sort(int ac, char **av){
    if (ac < 2)
        throw std::runtime_error("need more params");
    else{
        if (!parsInputNstortData(ac, av))
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

