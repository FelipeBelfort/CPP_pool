#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <algorithm>
# include <list>
# include <vector>
# include <iostream>

class PmergeMe
{
private:
	std::list<int>	_unsorted_list;
	std::list<int>	_sorted_list;
	int				_tot;
public:
	PmergeMe(/* args */);
	~PmergeMe();
	PmergeMe(const PmergeMe &copy);
	PmergeMe	&operator=(const PmergeMe &copy);

	void	fillContainer(int argc, char **argv);
	void	sortList();
};

PmergeMe::PmergeMe(/* args */)
{
}

PmergeMe::~PmergeMe()
{
}



#endif
