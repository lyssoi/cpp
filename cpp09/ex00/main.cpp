#include "BitcoinExchange.hpp"

// csv 파일을 dv로 가지고 있고... input에 따른 값을 내라는건가


int main (int argc, char *argv[]) {
    if (argc != 2){
        std::cerr << "invalid arguments" << std::endl;
        return (0);
    }
    try {
        BitcoinExchange bitcoin;
        bitcoin.parseInputFile(static_cast<std::string>(argv[1]));
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}