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

bool RPN::doOperation(const std::string& op) {
    if (_nums.size() <= 1)
        throw(std::exception());

    double a, b;
    b = _nums.top();
    _nums.pop();
    a = _nums.top();
    _nums.pop();

    if (op == "+")
            _nums.push( a + b );
    else if (op == "-")
            _nums.push( a - b );
    else if (op == "*")
            _nums.push( a * b );
    else if (op == "/")
            _nums.push( a / b );
    else
        throw(std::exception());
    return (true);
}

static double getNumber(const std::string& s) {
    if (s.length() > 10)
        throw(std::exception());
    errno = 0;
    double n = std::strtod(s.c_str(), NULL);
    if (errno || n > std::numeric_limits<int>::max() || n < std::numeric_limits<int>::min())
        throw(std::exception());
    return (n);
}

bool RPN::addNumber(const std::string& s) {
    if (s.find_first_of("0123456789") == std::string::npos)
        return (false);

    if (s.find_last_of("+-") != std::string::npos
        && s.find_last_of("+-") != 0)
        return (false);

    _nums.push(getNumber(s));
    return (true);
}

bool RPN::calculate(const std::string& input) {
    if (!validateInput(input)) {
        std::cout << "Error" << std::endl;
        return (false);
    }

    try {
        std::stringstream ss(input);
        std::string s;
        while (getline(ss, s, ' ')) {
            if (s.empty())
                continue;
            if (!addNumber(s))
                doOperation(s);
        }
        if (_nums.size() != 1) {
            throw(std::exception());
        }
    } catch (const std::exception&) {
        std::cout << "Error" << std::endl;
        return (false);
    }
    std::cout << _nums.top() << std::endl;
    return (true);
}
