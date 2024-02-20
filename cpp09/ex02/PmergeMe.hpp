#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <algorithm>
# include <list>
# include <vector>
# include <iostream>

class PmergeMe
{
private:
	std::vector<int>	_unsorted_vector;
	std::vector<int>	_sorted_vector;
	int				_tot;
public:
	PmergeMe(/* args */);
	~PmergeMe();
	PmergeMe(const PmergeMe &copy);
	PmergeMe	&operator=(const PmergeMe &copy);

	void	fillContainer(int argc, char **argv);

	template <typename T>
	void	sortList(std::vector<T> unsorted);
};

PmergeMe::PmergeMe(/* args */)
{
}

PmergeMe::~PmergeMe()
{
}



#endif
