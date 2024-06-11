#ifndef ITER_H
# define ITER_H
#include <iostream>
#include <sstream>

template < typename T >
void	iter(T *arr, unsigned int len, void (*f)(T const &)) {
	if (!arr)
		return;
	for (unsigned int i = 0; i < len ; i++)
		f(arr[i]);
	return;
}

#endif