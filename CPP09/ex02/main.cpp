#include "PmergeMe.hpp"

unsigned int ft_stou(const std::string& str)
{
	unsigned int num;
	std::stringstream ss(str);

	ss >> num;
	return num;
}

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "Error : No arguments";
		return(0);
	}

	PmergeMe pmm;

	try
	{
		// Check for potential other chars than numeric or space
		for (int i = 1; i < ac; i++)
		{
			if (std::string(av[i]).find_first_not_of("0123456789 ") != std::string::npos)
				throw PmergeMe::InvalidElementException();
		}

		// Pre-parse to check if there's duplicated arguments
		std::vector<unsigned int>temp;
		for (int i = 1; i < ac; i++)
			temp.push_back(ft_stou(av[i]));

		std::vector<unsigned int>::iterator itr;
		std::vector<unsigned int>::iterator itr2;
		for (itr = temp.begin(); itr != temp.end(); itr++)
		{
			for (itr2 = itr + 1; itr2 != temp.end(); itr2++)
			{
				if (*itr2 == *itr)
					throw PmergeMe::InvalidElementException();
			}
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return(0);
	}

	pmm.sort_vectors(ac, av);
	std::cout << std::endl;
	pmm.sort_lists(ac, av);
	return(0);
}