#include "RPN.hpp"

RPN::RPN(){}
RPN::RPN(const RPN &other){*this = other;}
RPN &RPN::operator=(const RPN &other){
    if (this != &other)
        this->stk = other.stk;
    return *this;
}
RPN::~RPN(){}

bool isOperation(const std::string &token){
    if (token.size() != 1)
        return false;
    if (token == "+" || token == "-" || token == "*" || token == "/")
        return true;
    return false;
}

bool isDigitToken(const std::string &token) {
    return token.size() == 1 && std::isdigit(token[0]);
}

double operation(double a, double b, std::string token){
    if (token == "+")
        return (a + b);
    if (token == "-")
        return (b - a);
    if (token == "*")
        return (a * b);
    if (token == "/"){
        if (a == 0)
            throw std::runtime_error("Error: Division by zero");
        else
            return (b / a);
    }
    return 0;
}

void RPN::operationProcessing(std::string input){
    if (input.empty())
        throw std::runtime_error("input empty");
    std::stringstream ss(input);
    std::string token;
    while(ss >> token){
        if (isOperation(token)){
            if (stk.size() < 2)
                throw std::runtime_error("Error: Not enough operands");
            double a = stk.top(); stk.pop();
            double b = stk.top(); stk.pop();
            double result = operation(a, b, token);
            stk.push(result);
        }
        else{
            if (isDigitToken(token))
                stk.push(std::atoi(token.c_str()));
            else
                throw std::runtime_error("number not valid");
        }
    }
    if (stk.size() != 1)
        throw std::runtime_error("Error: Invalid RPN expression");
    else
        std::cout << stk.top() << std::endl;
}

