#include "PmergeMe.hpp"

void	PmergeMe::fillContainer(int argc, char **argv)
{
	long long int	tmp;
	std::string		str;

	for (size_t i = 1; i < argc; i++)
	{
		this->_tot++;
		str = argv[i];
		tmp = atol(argv[i]);
		if (tmp < 0)
			return ;
		if (str.find_first_not_of("0123456789") != std::string::npos)
			return;
		if (tmp > __INT_MAX__)
			return;
		this->_unsorted_vector.push_back(tmp);
	}

}

template <typename T>
void	PmergeMe::sortList(std::vector<T> unsorted)
{
	std::vector<T>	sorted;
	size_t			size = unsorted.size();

	size -= size % 2;
	for (size_t i = 0; i < size; i++)
	{
		std::pair<T, T>	pair;
		if (unsorted[i] < unsorted[i + 1])
		{
			pair.first = unsorted[i];
			pair.second = unsorted[i + 1];
		}
		else
		{
			pair.first = unsorted[i + 1];
			pair.first = unsorted[1];
		}
	}

}


/***
 *	criar pares
 *	
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
*/
