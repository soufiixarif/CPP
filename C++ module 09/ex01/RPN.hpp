#pragma once
#include <iostream>
#include <stack>

class RPN {
    private:
        std::stack<double> stk;
    public:
        RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();
        
        void operationProcessing(std::string input);
};