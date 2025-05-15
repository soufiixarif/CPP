#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &other){(void)other;}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other){(void)other;return *this;}

ScalarConverter::~ScalarConverter(){}

bool isChar(std::string literal){
    return(literal.length() == 1 && !isdigit(literal[0]));
}

bool isInt(std::string literal){
    int i = 0;
    if (literal[i] == '+' || literal[i] == '-')
        i = 1;
    if (!literal[i])
        return false;
    while (literal[i]){
        if (!isdigit(literal[i]))
            return false;
        i++;
    }
    return true;
}

void ft_cout(){}

void ScalarConverter::convert(std::string literal){}