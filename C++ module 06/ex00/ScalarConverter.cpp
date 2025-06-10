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
    literal.resize(literal.size() - 1);
    if (literal[literal.size() - 1] == '.')
        return false;
    int i = 0;
    int count = 0;
    if (literal[i] == '+' || literal[i] == '-')
        i++;
    int tmp = i;
    if (literal[i] == '.')
        return 0;
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
    if (literal[literal.size() - 1] == '.')
        return false;
    int i = 0;
    int count = 0;
    if (literal[i] == '+' || literal[i] == '-')
        i++;
    if (literal[i] == '.')
        return 0;
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

bool is_displayable(double c){
    return (c >= 32 && c <= 126);
}

void ft_cout(bool char_overf, bool int_overf, bool float_overf, bool double_overf, bool impossible, bool impossible_over, double d){
    if (impossible_over){
        std::cout << "char: impossible\n" << "int: impossible\n" << "float: nanf\n" << "double: nan" << std::endl;
        return ;
    }
    else if(impossible){
        std::cout << "char: impossible\n" << "int: impossible\n" << "float: impossible\n" << "double: impossible" << std::endl;
        return ;
    }
    if (char_overf)
        std::cout << "char: impossible" << std::endl;
    else if (!is_displayable(d))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << "\'" << static_cast<char>(d) << "\'" << std::endl;
    if (int_overf)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    if (float_overf)
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << std::fixed << std::setprecision(2) << static_cast<float>(d) << "f" << std::endl;
    if (double_overf)
        std::cout << "double: impossible" << std::endl;
    else
        std:: cout << "double: " << std::setprecision(2) << static_cast<double>(d) << std::endl;
        
}

bool int_overflow(double f){
    if (f > INT_MAX || f < INT_MIN)
        return true;
    return false;
}

bool char_overflow(double f){
    if (f > CHAR_MAX || f < CHAR_MIN)
        return true;
    return false;
}

void ScalarConverter::convert(std::string literal){
    double d = 0.0;
    bool impossible_over = false, impossible = false;
    bool int_overf = false, float_overf = false, double_overf = false, char_overf = false;
    std::stringstream store(literal);
    if (literal == "-inff" || literal == "+inff" || literal == "nanf" || \
        literal == "-inf" || literal == "+inf" || literal == "nan")
        impossible_over = true;
    if (isChar(literal)){
        std::cout << "char\n";
        d = static_cast<double>(literal[0]);
    }
    else if (isInt(literal) || isFloat(literal) || isDouble(literal)){
        std::cout << "int\n";
        store >> d;
        if (store.fail())
            double_overf = true;
        if (int_overflow(d))
            int_overf = true;
        if (char_overflow(d))
            char_overf = true;
    }
    else
        impossible = true;
    ft_cout(char_overf, int_overf, float_overf, double_overf, impossible, impossible_over, d);
}