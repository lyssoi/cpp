#ifndef RPN_HPP
#define RPN_HPP
#include <stack>
#include <sstream>
#include <iostream>
#include <exception>

enum {
    NOT_OP,
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE
};
class RPN {
    private:
        std::stack<int> stack;
        RPN(const RPN &tmp);
        RPN &operator=(const RPN &tmp);
        int isoperator(std::string token);
    public:
        RPN(){};
        ~RPN(){};
        void run(int argc, char *argv[]);
};
#endif
