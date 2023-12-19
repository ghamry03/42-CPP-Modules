#pragma once

#include <iostream>
#include <stack>
#include <list>
#include <stdlib.h>
#include <sstream>
#include <cerrno>
#include <limits>

class RPN {
private:
    std::stack< double, std::list<double> > _nums;

    bool validateInput(const std::string& input);
    bool addNumber(const std::string& s);
    bool doOperation(const std::string& op);

public:
    RPN(void);
    // RPN(const std::string & input);
    ~RPN(void);
    RPN(const RPN& copy);
    RPN & operator=(const RPN& copy);

    bool calculate(const std::string& input);
};
