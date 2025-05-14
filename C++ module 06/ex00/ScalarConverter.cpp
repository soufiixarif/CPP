#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &other){(void)other;}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other){(void)other;return *this;}

ScalarConverter::~ScalarConverter(){}

bool isChar(std::string literal){
    return(literal.length() == 1 && !isdigit(literal[0]));
}

void ScalarConverter::convert(std::string literal){
    std::string info;
    char c = 0;
    int i = 0;
    float f = 0.0f;
    double d = 0.0;
    std::stringstream ss(literal);
    if (isChar(literal)){
        info = "char";
        c = literal[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);

    }
    else
        std::cout << "rak a katkhawer a m3alem" << std::endl;
    if (!info.compare("char")){
        if (c >= 33 && c <= 126)
            std::cout << "char: " << "\'" << c << "\'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << std::fixed <<std::setprecision(1) << f << "f" <<  std::endl;
    std::cout << "double: " << d << std::endl;

}