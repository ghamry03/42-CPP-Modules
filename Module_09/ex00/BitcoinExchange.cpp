#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {
    _months[1] = 31; _months[2] = 28; _months[3] = 31; _months[4] = 30; _months[5] = 31; _months[6] = 30;
    _months[7] = 31; _months[8] = 31; _months[9] = 30; _months[10] = 31; _months[11] = 30; _months[12] = 31;
    initData(DATA_FILE);
}

BitcoinExchange::BitcoinExchange(const std::string& dataFile) {
    _months[1] = 31; _months[2] = 28; _months[3] = 31; _months[4] = 30; _months[5] = 31; _months[6] = 30;
    _months[7] = 31; _months[8] = 31; _months[9] = 30; _months[10] = 31; _months[11] = 30; _months[12] = 31;
    initData(dataFile);
}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & copy) { *this = copy; }

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & copy) {
    _data = copy._data;
    return (*this);
}

void BitcoinExchange::initData(const std::string& dataFile) {
    std::ifstream in;
    in.open(dataFile.c_str());

    if (!in.is_open())
        return; // TODO: throw an error
    std::string line;
    std::getline(in, line);
    if (line != "date,exchange_rate")
        std::cout << "data file doesn't start with 'date,exchange_rate', gonna skip first line" << std::endl;
    while (std::getline(in, line)) {
        try {
            size_t commaIndex = line.find(",");
            if (commaIndex == std::string::npos || commaIndex != line.find_last_of(","))
                throw (std::runtime_error("invalid data input"));
            int date = toDate(line.substr(0, commaIndex).c_str());
            float rate = toFloat(line.substr(commaIndex + 1, line.length() - commaIndex - 1));
            _data[date] = rate;
        } catch (const std::exception& e) {
            std::cout << "Data file line has syntax error [" << line << "]: "
                << e.what() << std::endl;
        }
    }
    in.close();
}

float BitcoinExchange::getValue(int date, float amount) const {
    if (amount < 0)
        throw (std::runtime_error("not a positive number."));
    else if (amount > 1000)
        throw (std::runtime_error("too large a number."));

    std::map<int, float>::const_iterator it = _data.lower_bound(date);
    if (it == _data.end())
        throw (std::runtime_error("invalid date"));
    return (amount * it->second);
}

bool BitcoinExchange::run(const std::string& inputFile) {
    std::ifstream in;
    in.open(inputFile.c_str());

    if (!in.is_open()) {
        std::cout << "Error: can't open input file" << std::endl;
        return (false);
    }
    std::string line;
    std::getline(in, line);
    if (line != "date | value")
        std::cout << "input file doesn't start with 'date | value', gonna skip first line" << std::endl;
    while(getline(in, line)) {
        try {
            if (!_data.size())
                throw (std::runtime_error("empty data set"));
            size_t pipeIndex = line.find("|");
            if (pipeIndex == std::string::npos || pipeIndex != line.find_last_of("|"))
                throw (std::runtime_error("can't find pipe"));
            info cur;
            cur.date = toDate(line.substr(0, pipeIndex).c_str());
            cur.amount = toFloat(line.substr(pipeIndex + 1, line.length() - pipeIndex - 1));
            cur.value = getValue( cur.date, cur.amount);
            std::cout << cur << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    in.close();
    return (true);
}

std::ostream& operator<<(std::ostream& ss, const info& in) {
    int year = in.date / 10000;
    int month = (in.date / 100) % 100;
    int day = in.date % 100;

     std::cout << std::setfill('0') << std::setw(4) << year << "-"
        << std::setw(2) << month << "-" << std::setw(2) << day
        <<  " => " << in.amount << " = " << in.value;
    return (ss);
}

int BitcoinExchange::toDate(const std::string& dateStr) const {
    int year, month, day;
    if (sscanf(dateStr.c_str(), DATE_FORMAT, &year, &month, &day) != 3)
        throw (std::runtime_error("Bad input => " + dateStr));

    int date = year * 10000 + month * 100 + day;
    bool isLeapYear = !(year % 400) || (!(year % 4) && (year % 100));
    if (month <= 12 && month >= 1) {
        if (day >= 1 && day <= _months.find(month)->second)
            return (date);
        else if (isLeapYear && month == 2 && day >= 1 && day <= 29)
            return (date);
    }
    throw (std::runtime_error("Bad input => " + dateStr));
}

float   BitcoinExchange::toFloat(const std::string& num) const {
    if (num.find_first_not_of("1234567890+. ") != std::string::npos)
        throw (std::runtime_error("not a positive number."));
    if (num.find_first_of(".") != num.find_last_of(".")
        || num.find_first_of("+") != num.find_last_of("+"))
        throw (std::runtime_error("invalid number syntax"));
    errno = 0;
    double n = std::strtod(num.c_str(), NULL);
    if (errno || (n > std::numeric_limits<float>::max()
        && n < std::numeric_limits<float>::min()))
        throw (std::runtime_error("too large a number. " + num));
    return (static_cast<float>(n));
}

/*
 *  constructor( string inputFile ):
 *      - check if the input file is valid
 *      - read and store the data file
 *
 *  exchangeAmount( date, amount )
 *      - check if date exists in _data using lower_bound
 *      - return ( amount * found->second )
 *
 *  exchange:
 *      - while file
 *          get line
 *          get date
 *          get amount
 *          final = exchangeAmount( date, amount )
 *          printLog( date, amout, final )
 *
 * toDate( string date ):
 *      - substr the YEAR, MONTH, DATE
 *      - create a map that has the number of days for each month
 *      - check if data is valid
 *          if not throw an exception
 *      - return date YYYYMMDD as an int
 *
 *  readData:
 *      - check if DATA_FILE exists
 *
 *  printLog( int date, float amount, float final ):
 *      - print date << " => " << amount << " = " << final << std::endl
 */
