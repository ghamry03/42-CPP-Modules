#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) : _error(true) {}

PmergeMe::~PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe & copy) {
    *this = copy;
}

PmergeMe & PmergeMe::operator=(const PmergeMe & copy) {
    this->_error = copy._error;
    this->_numsDqe = copy._numsDqe;
    this->_numsVec = copy._numsVec;
    return (*this);
}

PmergeMe::PmergeMe(char **av) : _error(false) {
    for (int i = 1; av[i] && !_error; i++) {
        if ( std::string(av[i]).length() > 10 ||
            std::string(av[i]).find_first_not_of("0123456789+") != std::string::npos)
            _error = true;
        else {
            int num = atoi(av[i]);
            if (num < 0 || std::atol(av[i]) > std::numeric_limits<int>::max())
                _error = true;
            else if (std::find(_numsVec.begin(), _numsVec.end(), num) != _numsVec.end())
                _error = true;
            else {
                _numsDqe.push_back(num);
                _numsVec.push_back(num);
            }
        }
        if (_error)
            std::cout << "Error" << std::endl;
    }
}

template <typename T>
void    PmergeMe::printNums(const T& nums) {
    for (typename T::const_iterator it = nums.begin(); it != nums.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

template <typename T>
int PmergeMe::binarySearch(const T& nums, int num, int left, int right) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > num)
            return (binarySearch(nums, num, left, mid - 1));
        return (binarySearch(nums, num, mid + 1, right));
    }
    return (left);
}


std::deque< ii_pair > PmergeMe::createPairs_dqe(std::deque<int>& nums) {
    int first, second;
    std::deque< ii_pair > numPairs;
    for (std::deque<int>::const_iterator it = nums.begin(); it != nums.end(); it++) {
        first = *it;
        second = *(++it);
        numPairs.push_back(std::make_pair(first, second));
    }
    return (numPairs);
}
void PmergeMe::sortEachPair_dqe(std::deque< ii_pair >& numPairs) {
    for (std::deque< ii_pair >::iterator it = numPairs.begin();
    it != numPairs.end(); it++) {
        if (it->first > it->second)
            std::swap(it->first, it->second);
    }
}

void PmergeMe::insertSortPairs_dqe(std::deque< ii_pair >& nums, size_t n) {
    if (n <= 1)
        return ;

    insertSortPairs_dqe(nums, n - 1);

    ii_pair lastPair = nums[n - 1];
    int i = n - 2;
    while (i >= 0 && nums[i].second > lastPair.second) {
        nums[i + 1] = nums[i];
        i--;
    }
    nums[i + 1] = lastPair;
}

std::deque<int> PmergeMe::binaryInsertion_dqe(std::deque< ii_pair >& pairs) {
    std::deque<int> a, b;

    for (std::deque< ii_pair >::const_iterator it = pairs.begin(); it != pairs.end(); it++) {
        b.push_back(it->first);
        a.push_back(it->second);
    }

    a.insert(a.begin(), *b.begin()); b.erase(b.begin());
    while (b.size()) {
        int loc = binarySearch(a, *b.begin(), 0, a.size());
        a.insert(a.begin() + (int)loc, *b.begin());
        b.erase(b.begin());
    }
    return (a);
}
std::deque<int> PmergeMe::mergeInsertSort_dqe(std::deque<int>& nums) {
    bool isOdd = nums.size() % 2 != 0;
    if (isOdd)
        nums.push_back(-1);

    std::deque< ii_pair > numPairs = createPairs_dqe(nums);
    sortEachPair_dqe(numPairs);
    insertSortPairs_dqe(numPairs, numPairs.size());
    nums = binaryInsertion_dqe(numPairs);

    if (isOdd)
        nums.erase(nums.begin());

    return (nums);
}

std::vector< ii_pair > PmergeMe::createPairs_vec(std::vector<int>& nums) {
    int first, second;
    std::vector< ii_pair > numPairs;
    for (std::vector<int>::const_iterator it = nums.begin(); it != nums.end(); it++) {
        first = *it;
        second = *(++it);
        numPairs.push_back(std::make_pair(first, second));
    }
    return (numPairs);
}

void PmergeMe::sortEachPair_vec(std::vector< ii_pair >& numPairs) {
    for (std::vector< ii_pair >::iterator it = numPairs.begin();
    it != numPairs.end(); it++) {
        if (it->first > it->second)
            std::swap(it->first, it->second);
    }
}

// Recursive insert sort in a descending order
void PmergeMe::insertSortPairs_vec(std::vector< ii_pair >& nums, size_t n) {
    if (n <= 1)
        return ;

    insertSortPairs_vec(nums, n - 1);

    ii_pair lastPair = nums[n - 1];
    int i = n - 2;
    while (i >= 0 && nums[i].second > lastPair.second) {
        nums[i + 1] = nums[i];
        i--;
    }
    nums[i + 1] = lastPair;
}

std::vector<int> PmergeMe::binaryInsertion_vec(std::vector< ii_pair >& pairs) {
    std::vector<int> a, b;

    for (std::vector< ii_pair >::const_iterator it = pairs.begin(); it != pairs.end(); it++) {
        b.push_back(it->first);
        a.push_back(it->second);
    }

    a.insert(a.begin(), *b.begin()); b.erase(b.begin());
    while (b.size()) {
        int loc = binarySearch(a, *b.begin(), 0, a.size());
        a.insert(a.begin() + (int)loc, *b.begin());
        b.erase(b.begin());
    }
    return (a);
}

std::vector<int>    PmergeMe::mergeInsertSort_vec(std::vector<int>& nums) {
    bool isOdd = nums.size() % 2 != 0;
    if (isOdd)
        nums.push_back(-1);

    std::vector< ii_pair > numPairs = createPairs_vec(nums);
    sortEachPair_vec(numPairs);
    insertSortPairs_vec(numPairs, numPairs.size());
    nums = binaryInsertion_vec(numPairs);

    if (isOdd)
        nums.erase(nums.begin());

    return (nums);
}

double PmergeMe::checkTime(std::deque<int>& nums) {
    mergeInsertSort_dqe(nums);
    clock_t start = clock();
    mergeInsertSort_vec(_numsVec);
    clock_t end = clock();
    double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
    return (time);
}

double PmergeMe::checkTime(std::vector<int>& nums) {
    mergeInsertSort_vec(nums);
    clock_t start = clock();
    mergeInsertSort_vec(_numsVec);
    clock_t end = clock();
    double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
    return (time);
}

bool PmergeMe::run(void) {
    if (_error)
        return (false);

    double time_dqe = checkTime(_numsDqe);
    double time_vec = checkTime(_numsVec);

    std::cout << "Before: "; printNums(_numsDqe); std::cout << std::endl;
    std::cout << "After: "; printNums(_numsVec); std::cout << std::endl;
    std::cout << "Time to process a range of " << _numsVec.size() << " elements with std::[deque] : "
        << time_dqe << " us" << std::endl;
    std::cout << "Time to process a range of " << _numsVec.size() << " elements with std::[vector] : "
        << time_vec << " us" << std::endl;
    return (true);
}
