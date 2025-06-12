#pragma once

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <limits>

class ScalarConverter{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();
    public:
        
        static void convert(std::string literal);
};