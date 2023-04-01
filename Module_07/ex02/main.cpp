#include "Array.hpp"

int main(void) {
    {
        Array <int> * test1 = new Array <int> (10); 

        std::cout << (*test1)[1] << std::endl;
        (*test1)[1] = 69;
        std::cout << (*test1)[1] << std::endl;
        delete test1;
    }
   
    std::cout << std::endl;

    {
        Array <std::string> test2( 2 );
        try {
            test2[0] = "test 0";
            test2[1] = "test 1";
            test2[2] = "test 2";
        } catch ( std::exception & e ) {
            std::cout << e.what() << std::endl; 
        }
        std::cout << test2[0] << std::endl;
        std::cout << test2[1] << std::endl;
    }
}
