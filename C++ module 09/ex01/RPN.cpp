#include "RPN.hpp"

RPN::RPN(){}
RPN::RPN(const RPN &other){*this = other;}
RPN &RPN::operator=(const RPN &other){
    if (this != &other)
        this->stk = other.stk;
    return *this;
}
RPN::~RPN(){}

void RPN::operationProcessing(std::string input){
    if (input.empty())
        throw std::runtime_error("input empty");
    std::stringstream ss(std::string input);
}

