#include "Array.hpp"

int main(void) {
    {
        Array <int> * test = new Array <int> (10); 

        std::cout << (*test)[1] << std::endl;
        (*test)[1] = 69;
        std::cout << (*test)[1] << std::endl;
        delete test;
    }
    std::cout << std::endl;
    {
        Array <std::string> test( 2 );
        try {
            test[0] = "test 0";
            test[1] = "test 1";
            test[2] = "test 2";
        } catch ( std::exception & e ) {
            std::cout << e.what() << std::endl; 
            std::cout << "size of array: " << test.size() << std::endl;
        }
        std::cout << test[0] << std::endl;
        std::cout << test[1] << std::endl;
        Array <std::string> test2;
        test2 = test;
        std::cout << test2[1] << std::endl;
        std::cout << "test size: " << test.size()
            << " test2 size: " << test2.size() << std::endl;
    }
}
