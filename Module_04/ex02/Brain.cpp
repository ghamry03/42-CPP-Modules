#include "Brain.hpp"

Brain::Brain( void ) {
    this->_ideas = new std::string[100];
    for (int i = 0; i < 100; i++) {
        this->_ideas[i] = "idk";
    }
    std::cout << "Brain constructor is called" << std::endl;
}

Brain::~Brain( void ) {
    delete [] this->_ideas;
    std::cout << "Brain desstructor is called" << std::endl;
}

Brain::Brain( Brain const & copy ) {
    std::cout << "Brain copy constructor is called" << std::endl;
    this->_ideas = NULL;
    *this = copy;
}

Brain & Brain::operator=( Brain const & copy ) {
    std::cout << "Brain copy assigment operator is called" << std::endl;
    if (this->_ideas)
        delete [] this->_ideas;
    this->_ideas = new std::string[100];
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = copy._ideas[i];
    return ( *this );
}

