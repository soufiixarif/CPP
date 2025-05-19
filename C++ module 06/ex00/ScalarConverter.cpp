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

bool isFloat(std::string literal){
    if (literal[literal.length() - 1] != 'f')        
        return false;
    literal.pop_back();
    int i = 0;
    int count = 0;
    if (literal[i] == '+' || literal[i] == '-')
        i++;
    int tmp = i;
    while (literal[i]){
        if (literal[i] == '.')
            count++;
        if (count > 1)
            return false;
        i++;
    }
    i = tmp;
    while (literal[i]){
        if (!isdigit(literal[i]) && literal[i] != '.')
            return false;
        i++;
    }
    return true;
}

bool isDouble(std::string literal){
    int i = 0;
    int count = 0;
    if (literal[i] == '+' || literal[i] == '-')
        i++;
    int tmp = i;
    while (literal[i]){
        if (literal[i] == '.')
            count++;
        if (count > 1)
            return false;
        i++;
    }
    i = tmp;
    while (literal[i]){
        if (!isdigit(literal[i]) && literal[i] != '.')
            return false;
        i++;
    }
    return true;
}

void ft_cout(std::string info, bool impossible, char c, int i, float f, double d){
    (void)c;
    (void)i;
    (void)f;
    (void)d;
    (void)info;
    if (impossible){
        std::cout << "char: impossible\n" << "int: impossible\n" << "float: nanf\n" << "double: nan" << std::endl;  
    }

}

void ScalarConverter::convert(std::string literal){
    std::string info;
    char c = 0;
    int i = 0;
    float f = 0.0f;
    double d = 0.0;
    bool impossible = false;
    if (literal == "-inff" || literal == "+inff" || literal == "nanf" || \
        literal == "-inf" || literal == "+inf" || literal == "nan")
            impossible = true;
    if (isChar(literal)){
        std::cout << "char" << std::endl;
        info = "char";
        c = literal[0];§
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
    }
    else if (isInt(literal))
        std::cout << "int" << std::endl;
    else if (isFloat(literal))
        std::cout << "float" << std::endl;
    else if(isDouble(literal))
        std::cout << "double" << std::endl;
    else
        std::cout << "tkhwira" << std::endl;
    ft_cout(info, impossible, c,i,f,d);
}