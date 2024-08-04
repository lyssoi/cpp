#include "RPN.hpp"
int main(int argc, char *argv[]) {
    try {
        if (argc != 2){
            throw std::runtime_error("Wrong arguments!");
        }
        RPN rpn;
        rpn.run(argc, argv);
    } catch (std::exception &e){
        std::cout << e.what() <<std::endl;
        return (0);
    }
}