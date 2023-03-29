#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(void) {
    std::cout << "Base destructor is called" << std::endl;
}

static Base * createA(void) {
    return (new A());
}

static Base * createB(void) {
    return (new B());
}

static Base * createC(void) {
    return (new C());
}

Base * generate(void) {
    Base * (*f[3])() = {&createA, &createB, &createC};
    
    // std::srand(static_cast<unsigned int>(time(NULL)));
    Base * ret = f[std::rand() % 3]();
    
    return (ret);
}

void identify(Base * p) {
    if (dynamic_cast<A *>(p))
        std::cout << "Identified type is A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "Identified type is B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "Identified type is C" << std::endl;
    else
        std::cout << "Can't identify object" << std::endl;
}

void identify(Base & p) {
    try {
        A & test = dynamic_cast<A &>(p);
        std::cout << "Identified type is A" << std::endl;
        (void)test;
        return ;
    } catch (std::exception & e) {}
    try {
        B & test = dynamic_cast<B &>(p);
        std::cout << "Identified type is B" << std::endl;
        (void)test;
        return ;
    } catch (std::exception & e) {}
    try {
        C & test = dynamic_cast<C &>(p);
        std::cout << "Identified type is C" << std::endl;
        (void)test;
        return ;
    } catch (std::exception & e) {}
    std::cout << "Can't identify object" << std::endl;
}
