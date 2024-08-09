#include "RPN.hpp"

RPN::RPN(const RPN &tmp) {
    *this = tmp;
}

RPN &RPN::operator=(const RPN &tmp) {
    if (this != &tmp) {
        this->stack = tmp.stack;
    }
    return (*this);
}

void RPN::run(int argc, char *argv[]) {
    (void)argc;
    std::stringstream ss(argv[1]);
    std::string token;
    int num;
    while (ss >> token) {
        int oper;
        oper = isoperator(token);
        if (oper != NOT_OP){
            long long rvalue, lvalue, result;
            result = 0;
            if (stack.empty())
                throw std::runtime_error("invalid input");
            rvalue = static_cast<long long>(stack.top());
            stack.pop();
            if (stack.empty())
                throw std::runtime_error("invalid input");
            lvalue = static_cast<long long>(stack.top());
            stack.pop();
            if (oper == PLUS) {
                result = lvalue + rvalue;
            } else if (oper == MINUS) {
                result = lvalue - rvalue;
            } else if (oper == MULTIPLY) {
                result = lvalue * rvalue;
            } else if (oper == DIVIDE) {
                if (rvalue == 0)
                    throw std::runtime_error("Error : Division by zero");
                result = lvalue / rvalue;
            }
            if (result > INT_MAX || result < INT_MIN){
                throw std::overflow_error("Error: Integer overflow on addition");
            }
            stack.push(static_cast<int> (result));
        }
        else {
            std::stringstream numss(token);
            if (!(numss >> num))
                throw std::runtime_error("invalid input: number err");
            if (num >= 10 || num <= -10)
                throw std::runtime_error("invalid input: The number exceeds the allowed limit");
            stack.push(num);
        }
    }
    while (!stack.empty())
    {
        std::cout << stack.top() << std::endl;
        stack.pop();
    }
}

int RPN::isoperator(std::string token){
    if (token == "+") {
        return PLUS;
    }
    if (token == "-") {
        return MINUS;
    }
    if (token == "*") {
        return MULTIPLY;
    }
    if (token == "/"){
        return DIVIDE;
    }
    return NOT_OP;
}