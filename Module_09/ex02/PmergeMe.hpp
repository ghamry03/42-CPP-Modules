#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <stdlib.h>
#include <limits>
#include <algorithm>

typedef std::pair<int, int> ii_pair;

class PmergeMe {
private:
    bool             _error;
    std::deque<int>  _numsDqe;
    std::vector<int> _numsVec;

    /* helper */
    template <typename T> void    printNums(const T& nums);
    std::vector< ii_pair > createPairs(std::vector<int>& nums);
    template <typename T> int binarySearch(const T& nums, int num, int low, int high);
    double checkTime(std::vector<int>& nums);
    double checkTime(std::deque<int>& nums);

    /* deque */
    std::deque< ii_pair > createPairs_dqe(std::deque<int>& nums);
    void sortEachPair_dqe(std::deque< ii_pair >& numPairs);
    void insertSortPairs_dqe(std::deque< ii_pair >& nums, size_t n);
    std::deque<int> binaryInsertion_dqe(std::deque< ii_pair >& pairs);
    std::deque<int> mergeInsertSort_dqe(std::deque<int>& nums);

    /* vector */
    std::vector< ii_pair > createPairs_vec(std::vector<int>& nums);
    void sortEachPair_vec(std::vector< ii_pair >& numPairs);
    void insertSortPairs_vec(std::vector< ii_pair >& nums, size_t n);
    std::vector<int> binaryInsertion_vec(std::vector< ii_pair >& pairs);
    std::vector<int> mergeInsertSort_vec(std::vector<int>& nums);

public:
    PmergeMe(void);
    PmergeMe(char** av);
    ~PmergeMe(void);
    PmergeMe(const PmergeMe & copy);
    PmergeMe & operator=(const PmergeMe & copy);

    bool run(void);
};

#endif
