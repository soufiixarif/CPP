#pragma once
#include <iostream>
#include <sstream>
#include <stack>

class RPN {
    private:
        std::stack<int> stk;
    public:
        RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();
        
        void operationProcessing(std::string input);
};