#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <limits>
# include <cstdlib>

enum inputType {
    normal,
    negInf,
    posInf,
    nan
};

class ScalarConverter {
    private:
                                                          ScalarConverter(void);
                                  ScalarConverter(const ScalarConverter & copy);
                                                         ~ScalarConverter(void);
                      ScalarConverter & operator=(const ScalarConverter & copy);

                     static    bool                                   _isDouble;
                     static    bool                                  _hasQuotes;
                     static    inputType                             _inputType;

                     static    bool      checkQuotes(const std::string & input);
                     static    bool      parseNumber(const std::string & input);

    public:
                     static    char    convertToChar(const std::string & input);
                     static     int     convertToInt(const std::string & input);
                     static   float   convertToFloat(const std::string & input);
                     static  double  convertToDouble(const std::string & input);
                     static    bool        printChar(const std::string & input);
                     static    bool         printInt(const std::string & input);
                     static    bool       printFloat(const std::string & input);
                     static    bool      printDouble(const std::string & input);
                     static    bool  printAllConversions(
                                                     const std::string & input);

                     class  OpenQuotesException: public std::exception {
                         public:
                                virtual const char * what( void ) const throw();
                     };

                     class  InvalidCharException: public std::exception {
                         public:
                                virtual const char * what( void ) const throw();
                     };

                     class  NonPrintableCharException : public std::exception {
                         public:
                                virtual const char * what( void ) const throw();
                     };

                     class  IntLimitException : public std::exception {
                         public:
                                virtual const char * what( void ) const throw();
                     };

                     class  InputIsNotDigit: public std::exception {
                         public:
                                virtual const char * what( void ) const throw();
                     };
};

#endif
