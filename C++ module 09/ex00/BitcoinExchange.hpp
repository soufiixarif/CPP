#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <iomanip>

class BitcoinExchange{
    private :
        std::map<std::string, double>Data;
        void getData(const std::string &DataName);

    public :
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();
        
        BitcoinExchange(std::string DataFile);

        void dataProcessing(std::string inputFileName);
        void printResult(std::string date, double value);
        void printData();// to remove it later
};