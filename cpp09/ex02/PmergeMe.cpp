#include "PmergeMe.hpp"

void	PmergeMe::fillContainer(int argc, char **argv)
{
	int			tmp;
	std::string	str;
	for (size_t i = 1; i < argc; i++)
	{
		this._tot++;
		str = argv[i];
		tmp = atol(argv[i]);
		if (tmp < 0)
			return ;
		if (str.find_first_not_of("0123456789") != std::string::npos)
			return;
		if (tmp > __INT_MAX__)
			return;
		_unsorted_list.push_back(tmp);
	}

}

void	PmergeMe::sortList()
{
	std::list<int>	l_list;
	std::list<int>	b_list;

	for (size_t i = 0; i < _tot; i++)
	{
		if (this->_unsorted_list[i] < this->_unsorted_list[i + 1])
		{
			l_list.push_back(this->_unsorted_list[i]);
		}
	}

}
