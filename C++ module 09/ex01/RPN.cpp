#include "RPN.hpp"

RPN::RPN(){}
RPN::RPN(const RPN &other){*this = other;}
RPN &RPN::operator=(const RPN &other){
    if (this != &other)
        this->stk = other.stk;
    return *this;
}
RPN::~RPN(){}

int applyOperation(int a, int b, std::string token){
    if (token[0] == '+'){
        // std::cout << a << "+" << b << "= "<< (a + b) << std::endl;
        return a + b;
    }
    if (token[0] == '-'){
        // std::cout << a << "-" << b << "= " << a - b << std::endl;
        return a - b;
    }
    if (token[0] == '*'){
        // std::cout << a << "*" << b << "= " << a * b << std::endl;
        return a * b;
    }
    if (token[0] == '/'){
        // std::cout << a << "/" << b << "= " << a / b << std::endl;
        if (b == 0)
            throw std::runtime_error("Error: Division by zero");
        return a / b;
    }
    return 0;
}
bool isOperator(std::string token){
    if (token.size() != 1)
        return false;
    if (token[0] == '-' || token[0] == '+' || token[0] == '*' || token[0] == '/')
        return true;
    return false;
}

bool isValidOperand(std::string token){
    if (token.size() != 1)
        return false;
    if (!isdigit(token[0]))
        return false;
    return true;
}

void RPN::operationProcessing(std::string input){
    if (input.empty())
        throw std::runtime_error("input empty");

    std::stringstream ss(input);
    std::string token;
    while(ss >> token){
        if (isValidOperand(token))
            this->stk.push(token[0] - '0');
        else if (isOperator(token)){
            if (stk.size() < 2)
                throw std::runtime_error("Error: Not enough operands for operation ");
            int b = stk.top(); stk.pop();
            int a = stk.top(); stk.pop();
            try{
                int result = applyOperation(a,b,token);
                stk.push(result);
            }catch(...){
                throw std::runtime_error("Error: Division by zero");
            }
        }
        else
            throw std::runtime_error("Error: Invalid token");
    }
    if (stk.size() != 1)
        throw std::runtime_error("Error: Invalid expression");
    std::cout << stk.top() << std::endl;
}

