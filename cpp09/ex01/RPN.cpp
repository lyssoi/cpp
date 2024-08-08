#include "RPN.hpp"

void RPN::run(int argc, char *argv[]) {
    (void)argc;
    std::stringstream ss(argv[1]);
    std::string token;
    int num;
    while (ss >> token) {
        int oper;
        oper = isoperator(token);
        // 10미만의 숫자만 다뤄야함 (그 이상은 예외처리!)
        if (oper != NOT_OP){
            int rvalue, lvalue, result;
            if (stack.empty())
                throw std::runtime_error("invalid input: rvalue err");
            rvalue = stack.top();
            stack.pop();
            if (stack.empty())
                throw std::runtime_error("invalid input: rvalue err");
            lvalue = stack.top();
            stack.pop();
            if (oper == PLUS) {
                result = lvalue + rvalue;
            } else if (oper == MINUS) {
                result = lvalue - rvalue;
            } else if (oper == MULTIPLY) {
                result = lvalue * rvalue;
            } else if (oper == DIVIDE) {
                result = lvalue / rvalue;
            }
            stack.push(result);
        }
        else {
            std::stringstream numss(token);
            if (!(numss >> num))
                throw std::runtime_error("invalid input: number err");
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