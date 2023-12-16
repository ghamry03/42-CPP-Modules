#pragma once

# include <iostream>
# include <map>
# include <cstdlib>
# include <fstream>
# include <cerrno>
# include <limits>
# include <string>
# include <iomanip>

# define DATA_FILE "./data.csv"
# define DATE_FORMAT "%d-%d-%d"

struct info {
    int date;
    float amount;
    float value;
};

class BitcoinExchange {
private:
    std::map<int, int>   _months;
    std::map<int, float> _data; // date, rate

    void    initData(const std::string&);
    float   getValue(int date, float amount) const;

    int     toDate(const std::string& dateStr) const;
    float   toFloat(const std::string& num) const;
public:
    BitcoinExchange(void);
    BitcoinExchange(const std::string& input);
    ~BitcoinExchange(void);
    BitcoinExchange(const BitcoinExchange & copy);
    BitcoinExchange & operator=(const BitcoinExchange & copy);

    bool    run(const std::string& inputFile);
};

std::ostream& operator<<(std::ostream& s, const info& in);
