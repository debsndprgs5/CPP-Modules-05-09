#ifndef SPAN_H
# define SPAN_H

#include <iostream>
#include <sstream> 
#include <algorithm>
#include <list>


class Span {
	private:
		unsigned int N;
		std::list<int> intlist;
	public:
	    Span(unsigned int N);
	    Span( const Span& src );
	    ~Span();
	    Span& operator=(const Span& rhs);
		static void addnumber();
		static void shortestSpan();
		static void longestSpan();

		class SizeMaxException : public std::exception {
			public:
				const char* what() const throw() {
					return "Size max reached already.";
			}
		};
};

#endif
