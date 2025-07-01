#include "PmergeMe.hpp"

//=============================Canonical Form==========================================
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

//==============================Display output==========================================

void PmergeMe::displayOutput(){
    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); i++){
        std::cout << vec[i] ;
        if (i != vec.size() - 1)
            std::cout << " ";
        else
            std::cout << std::endl;
    }
    std::cout << "After: ";
    for (size_t i = 0; i < sorted.size(); i++){
        std::cout << sorted[i] ;
        if (i != sorted.size() - 1)
            std::cout << " ";
        else
            std::cout << std::endl;
    }
    double vecSec = vectorEnd.tv_sec - vectorStart.tv_sec;
    double vecMiSec = vectorEnd.tv_usec - vectorStart.tv_usec;
    double vecTotal = (vecSec * 1000000.0 + vecMiSec);
    std::cout << "Time to process a range of " << vec.size() << " elements with std::[vector] : "<< std::fixed << std::setprecision(5) << vecTotal << " us" << std::endl;
    double deqSec = dequeEnd.tv_sec - dequeStart.tv_sec;
    double deqMiSec = dequeEnd.tv_usec - dequeStart.tv_usec;
    double deqTotal = (deqSec * 1000000.0 + deqMiSec);
    std::cout << "Time to process a range of " << vec.size() << " elements with std::[deque] : " << std::fixed << std::setprecision(5) << deqTotal << " us" << std::endl;

}

//==============================start sorting===========================================

void PmergeMe::sort(int ac, char **av){
    if (ac < 2)
        throw std::runtime_error("need more params");
    else{
        if (!parsInputNstortDataVec(ac, av))
            throw std::runtime_error("ERROR");
        else
            insertMergeVector();
        if (!parsInputNstortDataDeq(ac, av))
            throw std::runtime_error("ERROR");
        else
            insertMergeDeque();
        displayOutput();
    }
}

// =========================sort using Vectore===========================================

bool PmergeMe::parsInputNstortDataVec(int ac, char **av){

    gettimeofday(&vectorStart, NULL);
    for (int i = 1; i < ac; i++){
        std::stringstream ss(av[i]);
        int n;
        ss >> n;
        if (ss.fail())
            return false;
        else if (n < 0)
            return false;
        this->vec.push_back(n);
    }
    return true;
}

void sortpairsVec(std::vector<std::pair<int, int> > &pairs){
    std::vector<std::pair<int, int> >::iterator it;
    for(it = pairs.begin(); it != pairs.end(); it++){
        if (it->first < it->second)
            std::swap(it->first, it->second);
    }
}

void makeMainPendVec(std::vector<std::pair<int, int> > &pairs, std::vector<int> &main, std::vector<int> &pend){
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

void    mergeVec(std::vector<std::pair<int,int> > &pairs, int l, int m, int r){
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

void recursion_sortVec(std::vector<std::pair<int,int> > &pairs, int l, int r){
    if (l < r){
        int m = (l + r) / 2;
        recursion_sortVec(pairs, l, m);
        recursion_sortVec(pairs, m + 1, r);
        mergeVec(pairs, l, m, r);
    }
}


std::vector<int> jacobsthalgeneratorVec(int pendSize){
    std::vector<int> seqIndex;

    if (pendSize < 0)
        return seqIndex;

    seqIndex.push_back(0);

    std::vector<int> jacob;
    jacob.push_back(0);
    jacob.push_back(1);

    while (true) {
        int next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
        if (next > pendSize)
            break;
        jacob.push_back(next);
    }

    for (size_t i = 1; i < jacob.size(); ++i) {
        seqIndex.push_back(jacob[i]);

        int from = jacob[i] - 1;
        int to = jacob[i - 1];
        for (int j = from; j > to; --j) {
            seqIndex.push_back(j);
        }
    }

    int lastJacob = jacob.back();
    for (int i = lastJacob + 1; i <= pendSize; ++i) {
        seqIndex.push_back(i);
    }
    if (seqIndex.size() > 2)
        seqIndex.erase(seqIndex.begin() + 2);
    return seqIndex;
}

void PmergeMe::insertMergeVector(){
    int struggler = -1;
    bool odd = false;
    if (vec.size() % 2 != 0){
        struggler = *(vec.end() - 1);
        odd = true;
    }

    std::vector<std::pair<int, int> > pairs;
    size_t len = vec.size();

    if (odd)
        len = vec.size() - 1;
    for (size_t i = 0; i < len; i+=2)
        pairs.push_back(std::pair<int, int>(vec[i], vec[i + 1]));

    sortpairsVec(pairs);

    recursion_sortVec(pairs, 0, pairs.size() - 1);

    std::vector<int> main_chain;
    std::vector<int> pend_chain;

    makeMainPendVec(pairs, main_chain, pend_chain);


    std::vector<int> JacobIndex = jacobsthalgeneratorVec(pend_chain.size());

    for (size_t i = 0; i < JacobIndex.size(); ++i) {
        int pendIndex = JacobIndex[i];
        if (pendIndex >= static_cast<int>(pend_chain.size()))
            continue;

        int value = pend_chain[pendIndex];

        std::vector<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), value);
        main_chain.insert(pos, value);
    }

    if (struggler != -1) {
        std::vector<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), struggler);
        main_chain.insert(pos, struggler);
    }
    gettimeofday(&vectorEnd, NULL);
    sorted = main_chain;
}

// =========================sort using deque===========================================

bool PmergeMe::parsInputNstortDataDeq(int ac, char **av){
    gettimeofday(&dequeStart, NULL);
    for (int i = 1; i < ac; i++){
        std::stringstream ss(av[i]);
        int n;
        ss >> n;
        if (ss.fail())
            return false;
        else if (n < 0)
            return false;
        this->deq.push_back(n);
    }
    return true;
}

void sortpairsDeq(std::deque<std::pair<int, int> > &pairs){
    std::deque<std::pair<int, int> >::iterator it;
    for(it = pairs.begin(); it != pairs.end(); it++){
        if (it->first < it->second)
            std::swap(it->first, it->second);
    }
}

void makeMainPendDeq(std::deque<std::pair<int, int> > &pairs, std::deque<int> &main, std::deque<int> &pend){
    std::deque<std::pair<int, int> >::iterator it;
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

void    mergeDeq(std::deque<std::pair<int,int> > &pairs, int l, int m, int r){
    int len1, len2;
    len1 = m - l + 1;
    len2 = r - m;
    std::deque<std::pair<int, int> > vecL(len1), vecR(len2);

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

void recursion_sortDeq(std::deque<std::pair<int,int> > &pairs, int l, int r){
    if (l < r){
        int m = (l + r) / 2;
        recursion_sortDeq(pairs, l, m);
        recursion_sortDeq(pairs, m + 1, r);
        mergeDeq(pairs, l, m, r);
    }
}


std::deque<int> jacobsthalgeneratorDeq(int pendSize){//to change it later
    std::deque<int> seqIndex;

    if (pendSize < 0)
        return seqIndex;

    seqIndex.push_back(0);

    std::deque<int> jacob;
    jacob.push_back(0);
    jacob.push_back(1);

    while (true) {
        int next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
        if (next > pendSize)
            break;
        jacob.push_back(next);
    }

    for (size_t i = 1; i < jacob.size(); ++i) {
        seqIndex.push_back(jacob[i]);

        int from = jacob[i] - 1;
        int to = jacob[i - 1];
        for (int k = from; k > to; --k) {
            seqIndex.push_back(k);
        }
    }

    int lastJacob = jacob.back();
    for (int i = lastJacob + 1; i <= pendSize; ++i) {
        seqIndex.push_back(i);
    }
    if (seqIndex.size() > 2)
        seqIndex.erase(seqIndex.begin() + 2);
    return seqIndex;
}

void PmergeMe::insertMergeDeque(){
    int struggler = -1;
    (void)struggler;
    bool odd = false;
    if (deq.size() % 2 != 0){
        struggler = *(deq.end() - 1);
        odd = true;
    }

    std::deque<std::pair<int, int> > pairs;
    size_t len = deq.size();
    if (odd)
        len = deq.size() - 1;
    for (size_t i = 0; i < len; i+=2)
        pairs.push_back(std::pair<int, int>(deq[i], deq[i + 1]));

    sortpairsDeq(pairs);

    recursion_sortDeq(pairs, 0, pairs.size() - 1);

    std::deque<int> main_chain;
    std::deque<int> pend_chain;

    makeMainPendDeq(pairs, main_chain, pend_chain);


    std::deque<int> JacobIndex = jacobsthalgeneratorDeq(pend_chain.size());

    for (size_t i = 0; i < JacobIndex.size(); ++i) {
        int pendIndex = JacobIndex[i];
        if (pendIndex >= static_cast<int>(pend_chain.size()))
            continue;

        int value = pend_chain[pendIndex];

        std::deque<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), value);
        main_chain.insert(pos, value);
    }

    if (struggler != -1) {
        std::deque<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), struggler);
        main_chain.insert(pos, struggler);
    }
    gettimeofday(&dequeEnd, NULL);
}