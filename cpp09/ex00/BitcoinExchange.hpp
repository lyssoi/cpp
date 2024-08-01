#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <sstream>

enum {
    FORMERR,
    BADINPUT
};
class BitcoinExchange
{
private:
    std::map<unsigned int, float> coinmap; // csv 파일에서 읽어와서 저장해야함. 날짜는 int형으로,
    //std::string filename; 
    BitcoinExchange(const BitcoinExchange & temp);
    BitcoinExchange &operator=(const BitcoinExchange &temp);
public:
    BitcoinExchange(/* args */);
    ~BitcoinExchange();
    void parseData(); // csv 파일 읽어와서 파싱함., csv 파일이 없거나 여기서 에러가 있으면 그냥 throw로 중단해버리고
    void parseInputFile(std::string filename); // input 읽어와서 파싱. 여기서는 문제 있으면 Error를 출력하고, 문제가 없으면 제대로 된 값을 출력한다.
    void printValue(unsigned int date, float value, std::string date_str); // 2011-01-03 => 3 = 0.9 형식으로 출력
    float findCloseBitcoin(unsigned int date);
    unsigned int checkDate(std::string str); // date 유효한지 체크함! 
    float checkValue(std::string str);
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