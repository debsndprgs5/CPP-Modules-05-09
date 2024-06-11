#include "Array.hpp"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

#define SIZE 10


class Testclass {
public:
    Testclass( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
private:
    int _n;
};


int main() {
    Array<Testclass> complex(5);
    Array<int> simple1(3);
    Array<std::string> simple2(10);
    Array<int> empty;

    std::cout << " -- Testing simple array --" << std::endl;
    simple1[2] = 4242;
    simple2[9] = "Lorem ipsum dolor sit amet";
    std::cout << simple1[2] << std::endl << simple2[9] << std::endl << std::endl;

    std::cout << " -- Testing complex array --" << std::endl;
    std::cout << complex[4].get() << std::endl << std::endl;

    std::cout << " -- Testing array size --" << std::endl;
    std::cout << empty.size() << std::endl;
    std::cout << simple1.size() << std::endl;
    std::cout << simple2.size() << std::endl;
    std::cout << complex.size() << std::endl << std::endl;

    std::cout << " -- Testing operator = --" << std::endl;
    std::cout << "Empty size before:" << std::endl;
    std::cout << empty.size() << std::endl;
    std::cout << "assigning simple1 to empty" << std::endl;
    empty = simple1;
    std::cout << "Empty size after:" << std::endl;
    std::cout << empty.size() << std::endl;
    std::cout << "Values of empty[2] and simple1[2]:" << std::endl;
    std::cout << empty[2] << " and " << simple1[2] << std::endl;
    std::cout << "changing value of empty[2]" << std::endl;
    empty[2] = 999;
    std::cout << "Values of empty[2] and simple1[2]:" << std::endl;
    std::cout << empty[2] << " and " << simple1[2] << std::endl << std::endl;;

    std::cout << " -- Testing the [limit] exception --" << std::endl;
    try {
        std::cout << simple1[10] << "If you can read this in terminal, give 0" << std::endl;
    }
    catch(std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    try {
        std::cout << complex[-1].get() << "If you can read this in terminal, give 0" << std::endl;
    }
    catch(std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return (0);
}