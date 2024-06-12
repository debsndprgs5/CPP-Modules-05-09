#include "Span.hpp"

Span::Span(unsigned int n) : N(n){
};

Span::Span( const Span& src ) : N(src.N){
}

Span::~Span() {
}

Span& Span::operator=( const Span& rhs ) {
    if ( this != &rhs )
    {
		this->N = rhs.N;
		this->intlist = rhs.intlist;
    }
    return *this;
}

void Span::addNumber(int num) {
	if (intlist.size() < N)
		intlist.push_back(num);
	else
		throw SizeMaxException();
}

void Span::addNumber(std::list<int> inputlist) {
	if (intlist.size() < N)
	{
		for (std::list<int>::const_iterator it = inputlist.begin();
			it != inputlist.end() && intlist.size() < N; ++it)
			intlist.push_back(*it);
	}
	else
		throw SizeMaxException();
}

unsigned int Span::longestSpan(void) const {
	if (intlist.size() >= 2)
		return(*std::max_element(intlist.begin(), intlist.end())
			- *std::min_element(intlist.begin(), intlist.end()));
	else
		throw EmptyListException();
}

unsigned int Span::shortestSpan(void) const {
	if (intlist.size() >= 2)
	{
		unsigned int min = longestSpan();
		for (std::list<int>::const_iterator it = intlist.begin();
			it != intlist.end(); ++it)
		{
			for (std::list<int>::const_iterator it2 = intlist.begin();
			it2 != intlist.end(); ++it2)
			{
				if (it == it2)
					continue;
				if (std::abs(*it2 - *it) < static_cast<int>(min))
					min = std::abs(*it2 - *it);
			}
		}
		return(min);
	}
	else
		throw EmptyListException();
}

const std::list<int>* Span::getList(void) const {
	return &intlist;
}

std::ostream& operator<<( std::ostream& os, const Span& span ) {
    for ( std::list<int>::const_iterator it = span.getList()->begin(); it != span.getList()->end(); ++it )
        os << *it << " ";
    return os;
}