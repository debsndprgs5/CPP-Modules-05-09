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
		void addNumber(int num);
		void addNumber(std::list<int> inputlist);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
		const std::list<int>* getList(void)	const;

		class SizeMaxException : public std::exception {
			public:
				const char* what() const throw() {
					return "Size max reached already.";
			}
		};

		class EmptyListException : public std::exception {
			public:
				const char* what() const throw() {
					return "List is empty or too small to be processed.";
			}
		};
};

std::ostream& operator<<( std::ostream&, const Span& );

#endif
