#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <climits>
# include <cstdlib>

class ScalarConverter {
    private:
                                                          ScalarConverter(void);
                                  ScalarConverter(const ScalarConverter & copy);
                                                         ~ScalarConverter(void);
                      ScalarConverter & operator=(const ScalarConverter & copy);

                     static    bool      parseNumber(const std::string & input);

    public:
                     static    char    convertToChar(const std::string & input);
                     static     int     convertToInt(const std::string & input);
                     static   float   convertToFloat(const std::string & input);
                     static  double  convertToDouble(const std::string & input);

                     class  NotCharException : public std::exception {
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
