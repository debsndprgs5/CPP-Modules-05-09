#ifndef EASYFIND_H
# define EASYFIND_H
#include <iostream>
#include <sstream> 
#include <algorithm>

template <class T>
void easyfind (T &container, int b) {
	if (std::find(container.begin(), container.end(), b) != container.end())
		std::cout << "Value found." << std::endl;
	else
		std::cout << "Value not found." << std::endl;
}

#endif