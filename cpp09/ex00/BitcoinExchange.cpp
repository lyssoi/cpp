#include "BitcoinExchange.hpp"

const char *BitcoinExchange::fileOpenError::what() const throw() {
    return ("Error: could not open file.");
}

const char *BitcoinExchange::formException::what() const throw() {
    return ("Error : file doesn't fit form!");
}

const char *BitcoinExchange::badInputDate::what() const throw() {
    return ("Error : Bad input => ");
}

const char *BitcoinExchange::notFloatNum::what() const throw() {
    return ("Error : not a Float num");
}

const char *BitcoinExchange::notPositive::what() const throw() {
    return ("Error : not a positive number");
}

const char *BitcoinExchange::tooLaregeNum::what() const throw() {
    return ("Error : too large a number");
}

const char *BitcoinExchange::notValidData::what() const throw() {
    return ("Error : not valid data. ");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &temp) {
    *this = temp;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &temp){
    if (this != &temp) {
        this->coinmap = temp.coinmap;
    }
    return *this;
}

BitcoinExchange::BitcoinExchange()
{
    parseData();
}

BitcoinExchange::~BitcoinExchange()
{
}

bool BitcoinExchange::strToInt(std::string str, int &num){
    std::stringstream ss(str);
    std::string remain;
    ss >> num;
    if (ss.fail()) {
        return false;
    }
    ss >> remain;
    if (!remain.empty()) {
        return false;
    }
    return true;
}

bool BitcoinExchange::strToFloat(std::string str, float &num) {
    std::stringstream ss(str);
    std::string remain;
    ss >> num;
    if (ss.fail()) {
        return false;
    }
    ss >> remain;
    if (!remain.empty()) {
        return false;
    }
    return true;
}


bool BitcoinExchange::notSpace(unsigned char ch) {
    return !std::isspace(ch);
}

void BitcoinExchange::trim(std::string &str) {
    str.erase(std::find_if(str.rbegin(), str.rend(),notSpace).base(), str.end()); // trimRight
    str.erase(str.begin(), std::find_if(str.begin(), str.end(), notSpace)); // trimLeft
}

void BitcoinExchange::checkKey(std::string line, std::string key1, std::string key2, char delimiter) {
    std::stringstream ss(line);
    std::string key_date;
    std::string key_rate;
    std::string temp;
    if (!std::getline(ss, key_date, delimiter) || !std::getline(ss, key_rate, delimiter)) {
        throw std::runtime_error("Error : invalid key" + line);
    }
    trim(key_date);
    trim(key_rate);
    if (key_date != key1 || key_rate != key2) {
        throw std::runtime_error("Error : invalid key" + line);
    }
    if (std::getline(ss, temp, delimiter)) {
        throw std::runtime_error("Error : invalid key" + line);
    }
}

void BitcoinExchange::parseData() {
    std::ifstream data;
    data.open("data.csv");
    if (!data.is_open()){
        throw BitcoinExchange::fileOpenError();
    }
    std::string line;
    std::getline(data, line);
    checkKey(line, "date","exchange_rate", ',');
    while(!data.eof() && std::getline(data, line)) {
        std::string date;
        std::string value;
        std::string tmp;
        std::stringstream ss(line);
        unsigned int validDate;
        float validValue;

        if (!std::getline(ss, date, ',') || !std::getline(ss, value, ',')) {
            throw notValidData();
        }
        if (std::getline(ss, tmp, ',')) {
            throw notValidData();
        }
        trim(date);
        trim(value);
        try {
        validDate = checkDate(date);
        } catch (std::exception &e) {
            throw notValidData();
        }
        if (!strToFloat(value,validValue))
            throw std::runtime_error("data : not valid rate => " + value);
        if (validValue < 0){
            throw std::runtime_error("data : not valid rate => " + value);
        }
        coinmap[validDate] = validValue;
    }
    if (coinmap.size() < 1)
        throw notValidData();
}

float BitcoinExchange::checkValue(std::string str){
    float value;
    if (!strToFloat(str,value)) {
        throw notFloatNum();
    }
    if (value < 0){
        throw notPositive();
    }
    if (value > 1000) {
        throw tooLaregeNum();
    }
    return value;
}

void BitcoinExchange::parseInputFile(std::string filename) {
    std::ifstream data;
    data.open(filename);
    if (!data.is_open()){
        throw BitcoinExchange::fileOpenError();
    }
    std::string line;
    std::getline(data, line);
    checkKey(line, "date","value", '|');
    while(!data.eof() && std::getline(data, line)) {
        std::string date;
        std::string value;
        std::string tmp;
        std::stringstream ss(line);
        unsigned int validDate;
        float validValue;
        if (!std::getline(ss, date, '|') || !std::getline(ss, value, '|') || std::getline(ss, tmp, '|')) {
            std::cout << "Error : Bad input => " << line << std::endl;
            continue;
        }
        trim(date);
        trim(value);
        try {
            validDate = checkDate(date);
            validValue = checkValue(value);
            printValue(validDate, validValue, date);
        } catch(badInputDate &e) {
         std::cout << e.what() << date << std::endl;
        } catch (std::exception &e) {
         std::cout << e.what() << std::endl;
        }
    }
}

float BitcoinExchange::findCloseBitcoin(unsigned int date){
    std::map<unsigned int, float>::iterator it;
    it = coinmap.lower_bound(date);
    if (it != coinmap.end() && it->first == date){
        return it->second;
    }
    if (it == coinmap.begin()) {
        throw std::runtime_error("Error : the date is not in the DB => ");
    }
    if (it->first > date || it == coinmap.end()){
        it--;
    }
    return it->second;
};

void BitcoinExchange::printValue(unsigned int date, float value, std::string date_str) {
    float findValue;
    try {
        findValue = findCloseBitcoin(date);
        std::cout << date_str << " => " << value << " = " << findValue * value << std::endl;
    } catch (std::exception &e){
        std::cout << e.what() << date_str << std::endl;
    }
}

unsigned int BitcoinExchange::checkDate(std::string str) {
    std::string str_year;
    std::string str_month;
    std::string str_day;
    std::string tmp;
    std::stringstream ss(str);
    unsigned int date = 0;
    int year;
    int month;
    int day;
    int mdays[2][13] = {
        {0,31,28,31,30,31,30,31,31,30,31,30,31},
        {0,31,29,31,30,31,30,31,31,30,31,30,31}
    };

    if (!std::getline(ss, str_year, '-') || !std::getline(ss, str_month, '-') || !std::getline(ss, str_day, '-') || std::getline(ss, tmp, '-')) {
        throw formException();
    }
    if (!strToInt(str_year, year) || year <= 0 || year > 9999){
        throw badInputDate();
    }
    if (!strToInt(str_month, month) || month <= 0 || month > 12){
        throw badInputDate();
    }
    if (!strToInt(str_day, day) || day <= 0) {
        throw badInputDate();
    }
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        if (day > mdays[1][month]) {
            throw badInputDate();
        } 
    } else {
        if (day > mdays[0][month]) {
            throw badInputDate();
        }
    }
    date = year * 10000 + month * 100 + day;
    return date;
}