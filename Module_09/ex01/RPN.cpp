#include "RPN.hpp"

RPN::RPN(void) {}

// RPN::RPN(const std::string& input) {}

RPN::~RPN(void) {}

RPN::RPN(const RPN& copy) {
    *this = copy;
}

RPN& RPN::operator=(const RPN& copy) {
    this->_nums = copy._nums;
    return (*this);
}

bool RPN::validateInput(const std::string& input) {
    if (input.find_first_not_of("1234567890-+/* ") != std::string::npos)
        return (false);
    return (true);
}

void RPN::doOperation(char c) {
    ssize_t a, b;

    b = _nums.top();
    _nums.pop();
    a = _nums.top();
    _nums.pop();

    switch (c) {
        case '+':
            _nums.push( a + b );
            break;
        case '-':
            _nums.push( a - b );
            break;
        case '*':
            _nums.push( a * b );
            break;
        case '/':
            _nums.push( a / b );
            break;
    }
}

bool RPN::calculate(const std::string& input) {
    if (!validateInput(input)) {
        std::cerr << "Error" << std::endl;
        return (false);
    }

    for ( std::string::const_iterator it = input.begin(); it != input.end(); it++ ) {
        if ( *it == ' ')
            continue;
        else if (isdigit(*it))
            _nums.push(*it - '0');
        else {
            if (_nums.size() > 1)
                doOperation(*it);
            else {
                std::cerr << "Error" << std::endl;
                return (false);
            }
        }
    }

    if (_nums.size() != 1)
        return (false);
    std::cout << _nums.top() << std::endl;
    return (true);
}
