#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <exception>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <list>

class PmergeMe {
	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe& to_copy);
		PmergeMe &operator=(const PmergeMe& to_copy);
		~PmergeMe(void);

		/* Both starting functions, everything else is static */
		void sort_vectors(int ac, char **av);
		void sort_lists(int ac, char **av);

		class InvalidElementException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif