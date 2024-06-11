#include "Span.hpp"

Span::Span(unsigned int n) : N(n){
};

Span::Span( const Span& src ) : N(src.N){
}

Span::~Span() {
}

Span& Span::operator=( const Span& rhs ) {
    if ( this != &rhs )
        N = rhs.N();
    return *this;
}

void Span::addnumber(int num) {
	if (intlist.size < N)
		intlist.push_back(num);
	else
		throw SizeMaxException();
}

void Span::shortestSpan(void) {
	if (intlist.size >= 2)
	{
		list<int>::iterator it;
		intlist.sort();
		
	}
}
