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

bool is_displayable(char c){
    return (c >= 32 && c <= 126);
}

void ft_cout(bool char_overf, bool int_overf, bool float_overf, bool double_overf, bool impossible, char c, int i, float f, double d){
    if (impossible){
        std::cout << "char: impossible\n" << "int: impossible\n" << "float: nanf\n" << "double: nan" << std::endl;
        return ;
    }
    if (char_overf)
        std::cout << "char: impossible" << std::endl;
    else if (!is_displayable(c))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << "\'" << c << "\'" << std::endl;
    if (int_overf)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;
    if (float_overf)
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << std::fixed << std::setprecision(2) << f << "f" << std::endl;
    if (double_overf)
        std::cout << "double: impossible" << std::endl;
    else
        std:: cout << "double: " << std::setprecision(2) << d << std::endl;
        
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
    char c = 0;
    int i = 0;
    float f = 0.0f;
    double d = 0.0;
    bool impossible = false;
    bool int_overf = false, float_overf = false, double_overf = false, char_overf = false;
    std::stringstream store(literal);
    if (literal == "-inff" || literal == "+inff" || literal == "nanf" || \
        literal == "-inf" || literal == "+inf" || literal == "nan")
        impossible = true;
    if (isChar(literal)){
        c = literal[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
    }
    else if (isInt(literal)){
        store >> i;
        if (store.fail())
            int_overf = true;
        if (char_overflow(i))
            char_overf = true;
        else
            c = static_cast<char>(i);
        f = static_cast<float>(i);
        d = static_cast<double>(i);
    }
    else if (isFloat(literal)){
        store >> f;
        if (store.fail())
            float_overf = true;
        if (char_overflow(i))
            char_overf = true;
        else
            c = static_cast<char>(i);
        if (int_overflow(f))
            int_overf = true;
        else
            i = static_cast<int>(f);
        d = static_cast<double>(f);
    }
    else if(isDouble(literal)){
        store >> d;
        if (store.fail())
            double_overf = true;
        if (char_overflow(i))
            char_overf = true;
        else
            c = static_cast<char>(i);
        if (int_overflow(d))
            int_overf = true;
        else
            i = static_cast<int>(d); 
        f = static_cast<float>(d);
    }
    else
        impossible = true;
    ft_cout(char_overf, int_overf, float_overf, double_overf, impossible, c, i, f, d);
}