#pragma once

#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>

class ScalarConverter{
    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();
        
        static void convert(std::string literal);
};