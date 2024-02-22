#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <algorithm>
# include <list>
# include <vector>
# include <iostream>

class PmergeMe
{
	typedef std::list<std::pair<int, int> >	t_pair;
private:
	std::vector<int>	_unsorted_vector;
	std::vector<int>	_sorted_vector;
	t_pair				_unsorted_list;
	std::list<int>		_sorted_list;
	int					_tot;
public:
	PmergeMe(int argc, char **argv);
	~PmergeMe();
	PmergeMe(const PmergeMe &copy);
	PmergeMe	&operator=(const PmergeMe &copy);

	void	fillContainer(int argc, char **argv);
	void	makePairList(int nb);
	void	mergeList(t_pair &lst);
	void	insertList(t_pair &lst);



	template <typename T>
	T		binarySearch(int nb, T ita, T itb);
	size_t	getGroupSize(size_t nb);
	// template <typename T>
	// void	sortList(std::vector<T> unsorted);
	void	printList(const std::list<int> &lst);
	void	printList(const t_pair &lst);

};



#endif