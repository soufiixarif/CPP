#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
    getData("data.csv");
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other){
    *this = other;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other){
    if (this == &other)
        return *this;
    this->Data = other.Data;
    return *this;
}
BitcoinExchange::~BitcoinExchange(){

}
BitcoinExchange::BitcoinExchange(std::string DataFile){
    getData(DataFile);
}

//--------------------------------------getting database----------------------------------

void BitcoinExchange::getData(const std::string &DataName){
    std::ifstream input(DataName.c_str());
    if (!input.is_open())
        throw std::runtime_error("ERROR: Can't open database file");
    std::string line;
    bool checker = false;
    while (getline(input, line)) {
        checker = true;
        std::stringstream ss(line);
        std::string date;
        std::string priceStr;
        getline(ss, date, ',');
        getline(ss, priceStr);
        double price = 0.0;
        std::stringstream(priceStr) >> price;
        this->Data[date] = price;
    }
    if (!checker)
        throw std::runtime_error("empty database");
    std::map<std::string, double>::iterator it = this->Data.end();
    --it;
    this->Data.erase(it);
}

//------------------------------------dataProcessing --------------------------------------

std::string strTrim(std::string &line){
    int start = 0;
    int end = line.size();

    while(line[start] && line[start] == ' ')
        start++;
    while (end >= 0 && line[end] == ' ')
        end--;
    return(line.substr(start, end - start - 1));
}

int checkLine(std::string line){
    std::stringstream ss(line);
    std::string part;
    int wordCount = 0;

    if (!line.empty() && (line[10] != ' ' || line[12] != ' ' || line[13] == ' '))
        return 0;
    while (getline(ss, part, '|'))
        wordCount++;
    return (wordCount == 2);
}

int validPrice(double price){
    return (price < 0 || price > 1000);
}

bool isleapyear(int year){
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int dayInMonth(int month, int year){
    switch(month){
        case 1: case 3: case 5: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 7: case 9: case 11:
            return 30;
        case 2:
            if (isleapyear(year))
                return 29;
            else
                return 28;
        default:
            return 0;
    }
}

bool validDate(std::string date){
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    std::stringstream ss(date);
    int year, month, day;
    char dash1, dash2;
    ss >> year >> dash1 >> month >> dash2 >> day;
    if(ss.fail() || dash1 != '-' || dash2 != '-')
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > dayInMonth(month, year))
        return false;
    if (year < 2009 || (year == 2009 && (month == 1 && day < 2)))
        return false;
    return true;
}

void BitcoinExchange::printResult(std::string date, double value){
    std::map<std::string, double>::iterator it = this->Data.lower_bound(date);
    if (it->first == date)
        std::cout << date << " => " << value << " = " << value * it->second << std::endl;
    else if (it != this->Data.end()){
        --it;
        std::cout << date << " => " << value << " = " << value * it->second << std::endl;
    }else{
        it = this->Data.end();
        --it;
        std::cout << date << " => " << value << " = " << value * it->second << std::endl;
    }
}

void BitcoinExchange::dataProcessing(std::string inputFileName){
    std::ifstream input(inputFileName.c_str());
    if (!input.is_open())
        throw std::runtime_error("ERROR: can't open the input file");
    std::string line;
    if (getline(input, line).fail()){
        input.close();
        throw std::runtime_error("can't read from input file");
    }
    if (line != "date | value"){
        input.close();
        throw std::runtime_error("bad header for the input file");
    }
    if (input.eof()){
        input.close();
        throw std::runtime_error("input file empty");
    }
    line.clear();
    while(getline(input, line)){
        if (!checkLine(line))
            std::cerr << "Error: bad input => " << line << std::endl;
        else{
            std::stringstream ss(line);
            std::string date;
            std::string valueStr;
            getline(ss, date, '|');
            date = strTrim(date);
            if (!validDate(date)){
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }
            getline(ss, valueStr);
            double value = 0.0;
            std::stringstream svalue(valueStr);
            svalue >> value;
            if (svalue.fail())
                std::cerr << "Error: bad input => " << line << std::endl;
            if (valueStr[1] == '-')
                std::cerr << "Error: not a positive number." << std::endl;
            else if (value > 1000)
                std::cerr << "Error: too large a number." << std::endl;
            else
                printResult(date, value);
        }
    }
    input.close();
}