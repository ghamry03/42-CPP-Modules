#include "ScalarConverter.hpp"
#include <cctype>
#include <limits>

bool ScalarConverter::_isDouble = false;
bool ScalarConverter::_hasQuotes = false;
bool ScalarConverter::_hasE = false;
inputType ScalarConverter::_inputType = normal;

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

bool    ScalarConverter::checkQuotes(const std::string & input) {
    size_t foundFirst = input.find('\'');
    if (foundFirst == std::string::npos)
        return (ScalarConverter::_hasQuotes);
    size_t foundSecond = input.find('\'', foundFirst + 1);
    
    if (foundFirst != 0 || foundSecond != input.length() - 1)
            throw ScalarConverter::OpenQuotesException();
    ScalarConverter::_hasQuotes = true;

    return (ScalarConverter::_hasQuotes);
}

bool    ScalarConverter::parseNumber(const std::string & input) {
    std::string numTypes[2][3] = {{"-inf", "+inf", "nan"},
                                {"-inff", "+inff", "nanf"}};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            if (input == numTypes[i][j]) {
                ScalarConverter::_inputType = static_cast<inputType>(j + 1);
                ScalarConverter::_isDouble = true;
                return (true);
            }
        }
    }

    size_t  found = input.find_last_of("+-");
    if (found != std::string::npos && found != 0 && input[found - 1] != 'e')
        throw ScalarConverter::InputIsNotDigit();


    found = input.find('f');
    if (found != std::string::npos && found != input.length() - 1)
        throw ScalarConverter::InputIsNotDigit();

    size_t foundFirst = input.find_first_of('.');
    size_t foundLast = input.find_last_of('.');
    if (foundFirst != foundLast)
        throw ScalarConverter::InputIsNotDigit();
    if (foundFirst != std::string::npos && input[foundFirst + 1])
        ScalarConverter::_isDouble = true;
    
    foundFirst = input.find_first_of('e');
    foundLast = input.find_last_of('e');
    std::string allowedCharForE = "0123456789+-";
    if (foundFirst != foundLast
        || allowedCharForE.find(input[foundLast + 1]) == std::string::npos)
        throw ScalarConverter::InputIsNotDigit();
    if (foundFirst != std::string::npos)
        ScalarConverter::_hasE = true;

    found = input.find_first_not_of("0123456789e.+-f");
    if (found != std::string::npos)
        throw ScalarConverter::InputIsNotDigit();

    return (true);
}


char    ScalarConverter::convertToChar(const std::string & input) {
    char ret;

    if (ScalarConverter::_inputType != normal)
        throw ScalarConverter::ImpossiblePrintException();

    if (ScalarConverter::_isDouble)
        throw ScalarConverter::InvalidCharException();

    std::string cleanedInput = input; 
    if (ScalarConverter::_hasQuotes) {
        cleanedInput = input.substr(1, input.length() - 2);
        if (cleanedInput.length() != 1)
            throw InvalidCharException();
        return (cleanedInput[0]);
    }
        
    try {
        ret = static_cast<char>(ScalarConverter::convertToInt(cleanedInput));
    }
    catch (std::exception & e) {
        throw ScalarConverter::InvalidCharException();
    }
    if (!std::isprint(ret))
        throw ScalarConverter::NonPrintableCharException();
    return (ret);
}

int     ScalarConverter::convertToInt(const std::string & input) {
    size_t      findDot;
    long        num;

    if (ScalarConverter::_inputType != normal)
        throw ScalarConverter::ImpossiblePrintException();

    std::string cleanedInput = input; 
    if (ScalarConverter::_hasQuotes)
        cleanedInput = input.substr(1, input.length() - 2);
        
    ScalarConverter::parseNumber(cleanedInput);

    findDot = cleanedInput.find(".");
    if (findDot == std::string::npos) {
        if (input.length() > 11)
            throw ScalarConverter::NumberNotInRangeException();
    }
    else if (findDot > 11)
        throw ScalarConverter::NumberNotInRangeException();

    num = atol(cleanedInput.c_str());
    if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
        throw ScalarConverter::NumberNotInRangeException();
    return (static_cast<int>(num));
}

float   ScalarConverter::convertToFloat(const std::string & input) {
    double num = convertToDouble(input);
    if (num > std::numeric_limits<float>::max() || num < std::numeric_limits<float>::min())
        throw ScalarConverter::NumberNotInRangeException();
    return (static_cast<float>(num));
}

double  ScalarConverter::convertToDouble(const std::string & input) {
    std::string cleanedInput = input; 
    if (ScalarConverter::_hasQuotes)
        cleanedInput = input.substr(1, input.length() - 2);
        
    ScalarConverter::parseNumber(cleanedInput);
    char **end = NULL;
    errno = 0;
    double ret = std::strtod(input.c_str(), end);
    if (errno)
        throw ScalarConverter::NumberNotInRangeException();

    return (ret);
}

bool    ScalarConverter::printChar(const std::string & input) {
    try {
        std::cout << "char:\t";
        char c = ScalarConverter::convertToChar(input);
        std::cout << "'" << c << "'" << std::endl;
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
        return (false);
    }
    return (true);
}

bool    ScalarConverter::printInt(const std::string & input) {
    try {
        std::cout << "int:\t";
        std::cout << ScalarConverter::convertToInt(input) << std::endl;
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
        return (false);
    }
    return (true);
}

bool    ScalarConverter::printFloat(const std::string & input) {
    try {
        std::cout << "float:\t";
        double num = ScalarConverter::convertToFloat(input);
        std::cout << num;
        if (!ScalarConverter::_isDouble && num == static_cast<int>(num))
            std::cout << ".0";
        std::cout << "f" << std::endl;
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
        return (false);
    }
    return (true); 
}

bool    ScalarConverter::printDouble(const std::string & input) {
    try {
        std::cout << "double:\t";
        double num = ScalarConverter::convertToDouble(input);
        std::cout << num;
        if (!ScalarConverter::_isDouble && num == static_cast<int>(num))
            std::cout << ".0";
        std::cout << std::endl;
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
        return (false);
    }
    return (true);
}

bool    ScalarConverter::printAllConversions(const std::string & input) {
    try {
        ScalarConverter::checkQuotes(input);
    } catch (std::exception & e) {
        std::cout << "Invalid input: "<< e.what() << std::endl;
        return (false);
    }
    try {
        ScalarConverter::parseNumber(input);
    } catch (std::exception & e) {}
    ScalarConverter::printChar(input);
    ScalarConverter::printInt(input);
    ScalarConverter::printFloat(input);
    ScalarConverter::printDouble(input);
   return (true);
}

const char * ScalarConverter::ImpossiblePrintException::what( void ) const throw() {
    return ("[impossible]");   
}

const char * ScalarConverter::OpenQuotesException::what( void ) const throw() {
    return ("[Input has open quotes]");   
}

const char * ScalarConverter::InvalidCharException::what( void ) const throw() {
    return ("[Invalid character]");   
}

const char * ScalarConverter::NonPrintableCharException::what( void ) const throw() {
    return ("[Non displayable]");   
}

const char * ScalarConverter::NumberNotInRangeException::what( void ) const throw() {
    return ("[Number is outside the range]");   
}

const char * ScalarConverter::InputIsNotDigit::what( void ) const throw() {
    return ("[Input isn't a digit]");   
}
