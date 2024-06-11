#include "easyfind.hpp"
#include <list>
#include <vector>

int main()
{
	std::list<int> intlist;
	std::vector<int> intvec;
//init list
	for (int i = 0; i <= 9; i++)
		intlist.push_back(i);
//init vector
	for (int i = 0; i <= 9; i++)
		intvec.push_back(i);
//should work
	easyfind(intlist, 3);
	easyfind(intvec, 3);
//should not work
	easyfind(intlist, 32);
	easyfind(intvec, 211);
//----------
	return(0);
}