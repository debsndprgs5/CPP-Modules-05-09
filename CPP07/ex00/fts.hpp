#ifndef FTS_H
# define FTS_H
#include <iostream>
#include <sstream> 

template <class T>
T max (T a, T b) {
	return(a>b?a:b);
}

template <class T>
T min (T a, T b) {
	return(a<b?a:b);
}

template <class T>
void swap (T &a, T &b) {
	T tmp;

	tmp = a;
	a = b;
	b = tmp;
}
#endif