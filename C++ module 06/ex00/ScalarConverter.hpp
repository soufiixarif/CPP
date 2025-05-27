#pragma once

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <climits>

class ScalarConverter{
    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();
        
        static void convert(std::string literal);
};