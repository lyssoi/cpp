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
    public:
        RPN(){};
        ~RPN(){};
        RPN(const RPN &tmp);
        RPN &operator=(const RPN &tmp);
        void run(int argc, char *argv[]);
        int isoperator(std::string token);
};
#endif
