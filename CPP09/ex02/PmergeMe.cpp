#include "PmergeMe.hpp"

# define MSECOND 100000

unsigned int ft_stou(const std::string& str);

PmergeMe::PmergeMe(void) {};

PmergeMe::PmergeMe(const PmergeMe& to_copy) {
	*this = to_copy;
};

PmergeMe& PmergeMe::operator=(const PmergeMe& to_copy) {
	(void)to_copy;
	return *this;
};

PmergeMe::~PmergeMe(void) {};

/* ----------------------------------------------------------- */
/*                         VECTOR PART                         */
/* ----------------------------------------------------------- */

// Print the vector
static void print_vec(std::vector<unsigned int>& vec)
{
	std::vector<unsigned int>::const_iterator itr;
	for (itr = vec.begin(); itr != vec.end(); itr++)
		std::cout << *itr << " ";
	std::cout << std::endl;
}

/* Merge the two vectors until they are both empty using merge sort algorythm,
returns the result */
static std::vector<unsigned int> merge_vectors(std::vector<unsigned int>& left,
	std::vector<unsigned int>& right)
{
	std::vector<unsigned int> result;

	// Merge left & right until one is empty
	while (!left.empty() && !right.empty())
	{
		if (left.front() <= right.front())
		{
			result.push_back(left.front());
			left.erase(left.begin());
		}
		else
		{
			result.push_back(right.front());
			right.erase(right.begin());
		}
	}

	// Get the potential remaining elements from the vectors, since only one is empty
	while (!left.empty())
	{
		result.push_back(left.front());
		left.erase(left.begin());
	}
	while (!right.empty())
	{
		result.push_back(right.front());
		right.erase(right.begin());
	}
	return(result);
}

/* Divide the vector in 2 halfs and sort thoses recursively using 
insertion algorythm */
static std::vector<unsigned int> merge_insert_vectors(std::vector<unsigned int>& vec)
{
	// a vector that has 0 or 1 element is already sorted
	if (vec.size() <= 1)
		return vec;

	// Divide the vector into two halves
	int mid = vec.size() / 2;
	std::vector<unsigned int> left(vec.begin(), vec.begin() + mid);
	std::vector<unsigned int> right(vec.begin() + mid, vec.end());

	// Recursive sort
	right = merge_insert_vectors(right);
	left = merge_insert_vectors(left);

	return merge_vectors(left, right);
}

// Starting function for sorting the vectors //

void PmergeMe::sort_vectors(int ac, char **av)
{
	std::vector<unsigned int> storage;

	for (int i = 1; i < ac; i++)
		storage.push_back(ft_stou(av[i]));

	std::cout << "<std::vector> Before sorting :" << std::endl;
	if (ac <= 1000) // Improve readability by not printing chars if there's more than 1000.
		print_vec(storage);

	//Complexity check
	std::clock_t start = std::clock();

	//Start processing
	storage = merge_insert_vectors(storage);

	double time_taken = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * MSECOND;

	std::cout << "<std::vector> After sorting : " << std::endl;
	if (ac <= 1000) // Improve readability by not printing chars if there's more than 1000.
		print_vec(storage);

	std::cout << "Complexity :" << std::endl << "Range : " << (ac - 1) << " elements." << std::endl
	<< "Time taken with <std::vector> : " << time_taken << " µs" << std::endl;
}


/* ----------------------------------------------------------- */
/*                         LIST PART                         */
/* ----------------------------------------------------------- */

// Print the list
static void print_list(std::list<unsigned int>& lst)
{
	std::list<unsigned int>::const_iterator itr;
	for (itr = lst.begin(); itr != lst.end(); itr++)
		std::cout << *itr << " ";
	std::cout << std::endl;
}

/* Literally the same functions used for vectors but using lists */
static std::list<unsigned int> merge_lists(std::list<unsigned int>& left,
	std::list<unsigned int>& right)
{
	std::list<unsigned int> result;

	// Merge left & right until one is empty
	while (!left.empty() && !right.empty())
	{
		if (left.front() <= right.front())
		{
			result.push_back(left.front());
			left.erase(left.begin());
		}
		else
		{
			result.push_back(right.front());
			right.erase(right.begin());
		}
	}

	// Get the potential remaining elements from the vectors, since only one is empty
	while (!left.empty())
	{
		result.push_back(left.front());
		left.erase(left.begin());
	}
	while (!right.empty())
	{
		result.push_back(right.front());
		right.erase(right.begin());
	}
	return(result);
}

/* Divide the vector in 2 halfs and sort thoses recursively using 
insertion algorythm */
static std::list<unsigned int> merge_insert_lists(std::list<unsigned int>& lst)
{
	// a list that has 0 or 1 element is already sorted
	if (lst.size() <= 1)
		return lst;

	// Divide the vector into two halves
	int mid = lst.size() / 2;
	std::list<unsigned int> left;
	std::list<unsigned int> right;

	for (int i = 0; i < mid; i++)
	{
		left.push_back(lst.front());
		lst.pop_front();
	}
	right = lst;

	// Recursive sort
	right = merge_insert_lists(right);
	left = merge_insert_lists(left);

	return merge_lists(left, right);
}

// Starting function for sorting the lists //

void PmergeMe::sort_lists(int ac, char **av)
{
	std::list<unsigned int> storage;

	for (int i = 1; i < ac; i++)
		storage.push_back(ft_stou(av[i]));

	std::cout << "<std::list> Before sorting :" << std::endl;
	if (ac <= 1000) // Improve readability by not printing chars if there's more than 1000.
		print_list(storage);

	//Complexity check
	std::clock_t start = std::clock();

	//Start processing
	storage = merge_insert_lists(storage);

	double time_taken = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * MSECOND;

	std::cout << "<std::list> After sorting : " << std::endl;
	if (ac <= 1000) // Improve readability by not printing chars if there's more than 1000.
		print_list(storage);

	std::cout << "Complexity :" << std::endl << "Range : " << (ac - 1) << " elements." << std::endl
	<< "Time taken with <std::list> : " << time_taken << " µs" << std::endl;
}

const char*	PmergeMe::InvalidElementException::what() const throw() {
	return "Error: Invalid element";
}