#include "ScalarConverter.hpp"



ScalarConverter::ScalarConverter(void) {
    std::cout << "ScalarConverter default constructor is called" << std::endl;
}

ScalarConverter::~ScalarConverter(void) {
    std::cout << "ScalarConverter destrutor is called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter & copy) {
    std::cout << "ScalarConverter copy constructor is called" << std::endl;
    *this = copy;
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter & copy) {
    std::cout << "ScalarConverter copy assignment operator is called" << std::endl;
    (void)copy;
    return (*this);
}

bool    ScalarConverter::parseNumber(const std::string & input) {
    size_t  found = input.find_last_of("+-");
    if (found != std::string::npos && found != 0)
        throw ScalarConverter::InputIsNotDigit();

    found = input.find('f');
    if (found != std::string::npos && found != input.length() - 1)
        throw ScalarConverter::InputIsNotDigit();

    size_t foundFirst = input.find_first_of('.');
    size_t foundLast = input.find_last_of('.');
    if (foundFirst != foundLast)
        throw ScalarConverter::InputIsNotDigit();

    found = input.find_first_not_of("0123456789.+-f");
    if (found != std::string::npos)
        throw ScalarConverter::InputIsNotDigit();

    return (true);
}


char    ScalarConverter::convertToChar(const std::string & input) {
    if (input.length() != 1 || std::isdigit(input[0]) || !std::isprint(input[0]))
        throw ScalarConverter::NotCharException();
    return (input[0]);
}

int     ScalarConverter::convertToInt(const std::string & input) {
    size_t      findDot;
    long        num;

    ScalarConverter::parseNumber(input);

    findDot = input.find(".");
    if (findDot == std::string::npos) {
        if (input.length() > 11)
            throw ScalarConverter::IntLimitException();
    }
    else if (findDot > 11)
        throw ScalarConverter::IntLimitException();

    num = atol(input.c_str());
    if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
        throw ScalarConverter::IntLimitException();
    return (static_cast<int>(num));
}

float   ScalarConverter::convertToFloat(const std::string & input) {
    ScalarConverter::parseNumber(input);
    return (static_cast<float>(std::atof(input.c_str())));
}

double  ScalarConverter::convertToDouble(const std::string & input) {
    ScalarConverter::parseNumber(input);
    return (static_cast<double>(std::stod(input)));
}

const char * ScalarConverter::NotCharException::what( void ) const throw() {
    return ("[Non displayable]");   
}

const char * ScalarConverter::IntLimitException::what( void ) const throw() {
    return ("[Number is outside Int range]");   
}

const char * ScalarConverter::InputIsNotDigit::what( void ) const throw() {
    return ("[Input isn't a digit]");   
}
