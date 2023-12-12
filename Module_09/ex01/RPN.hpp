#pragma once

#include <iostream>
#include <stack>
#include <list>

class RPN {
private:
    std::stack< ssize_t, std::list<ssize_t> > _nums;

    bool validateInput(const std::string& input);
    void doOperation(char c);

public:
    RPN(void);
    // RPN(const std::string & input);
    ~RPN(void);
    RPN(const RPN& copy);
    RPN & operator=(const RPN& copy);

    bool calculate(const std::string& input);
};
