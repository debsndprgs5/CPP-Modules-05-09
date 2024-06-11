#include "iter.hpp"

class Something {
public:
	Something( void ) : _n( 42 ) { return; }
	int get( void ) const { return this->_n; }
private:
	int _n;
};

std::ostream & operator<<( std::ostream & o, Something const & rhs ) { o << rhs.get(); return o; }

template< typename T >
void print( T const & x ) {
	std::cout << x << std::endl;
	return;
}

int main() {
	int intab[] = { 0, 1, 2, 3, 4 };
	Something randomtab[5];

	iter( intab, 5, print );
	iter( randomtab, 5, print );

	return 0;
}