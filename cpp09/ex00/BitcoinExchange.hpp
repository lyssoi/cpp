#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <sstream>
#include <limits>
#include <stdexcept>

enum {
    FORMERR,
    BADINPUT
};
class BitcoinExchange
{
private:
    std::map<unsigned int, float> coinmap;
    BitcoinExchange(const BitcoinExchange & temp);
    BitcoinExchange &operator=(const BitcoinExchange &temp);
public:
    BitcoinExchange();
    ~BitcoinExchange();
    void parseData(); 
    void parseInputFile(std::string filename);
    void printValue(unsigned int date, float value, std::string date_str);
    float findCloseBitcoin(unsigned int date);
    unsigned int checkDate(std::string str);
    float checkValue(std::string str);
    static bool notSpace(unsigned char ch);
    void trim(std::string &str);
    void checkKey(std::string line, std::string key1, std::string key2, char delimiter);
    bool strToFloat(std::string str, float &num);
    bool strToInt(std::string str, int &num);
    class fileOpenError : public std::exception {
        public:
            const char *what() const throw();
    };
    class formException : public std::exception {
        public:
            const char *what() const throw();
    };
    class badInputDate : public std::exception {
        public:
            const char *what() const throw();
    };
    class notFloatNum : public std::exception {
        public:
            const char *what() const throw();
    };
    class notPositive : public std::exception {
        public:
            const char *what() const throw();
    };
    class tooLaregeNum : public std::exception {
        public:
            const char *what() const throw();
    };
    class notValidData : public std::exception {
        public:
            const char *what() const throw();
    };
};

#endif