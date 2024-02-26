#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <algorithm>
# include <list>
# include <vector>
# include <iostream>
# include <sys/time.h>

# define DEBUG std::cout << "pas moi" << std::endl;
# define INDEX 1
# define SIZE 2
// # define INI 2

class PmergeMe
{
	typedef std::list<std::pair<int, int> >	t_pair_lst;
	typedef std::vector<std::pair<int, int> >	t_pair_vec;
	// typedef std::pair<std::list<int>::iterator, t_pair_lst::iterator>	t_insert_list;
	typedef std::pair<std::list<int>::iterator, int>	t_insert_list;
	typedef std::pair<std::vector<int>::iterator, int>	t_insert_vec;
private:
	std::vector<int>	_original;
	std::vector<int>	_sorted_vector;
	t_pair_vec			_unsorted_vector;
	t_pair_lst			_unsorted_list;
	std::list<int>		_sorted_list;
	double				_time_init;
	double				_time_list;
	double				_time_vector;
public:
	PmergeMe(int argc, char **argv);
	~PmergeMe();
	PmergeMe(const PmergeMe &copy);
	PmergeMe	&operator=(const PmergeMe &copy);

	//			Parsing		//

	void	fillContainer(int argc, char **argv);

	//			List		//

	void	makePairList(int nb);
	void	mergeList(t_pair_lst &lst);
	void	sortList(void);
	void	insertList(void);


	//			Vector		//

	void	makePairVector(int nb);
	void	mergeVector(t_pair_vec &vec);
	void	sortVector(void);
	void	insertVector(void);
	template <typename T>
	void	pushPair(T it, int i);

	//			Outils		//

	template <typename T>
	T		binarySearch(int nb, T ita, T itb);
	template <typename T>
	T		binarySearchVec(int nb, T ita, T itb);
	size_t	getGroupSize(size_t nb, size_t type);
	template <typename T>
	void	printList(const T &lst);
	void	printResult(void);
	double	getTime(void);
	void	putTime(double &type);

	class InputErrorException : public std::exception
	{
	public:
		const char	*what() const throw();
	};

	// template <typename T>
	// void	sortList(std::vector<T> unsorted);
	// void	printList(const std::vector<int> &vec);
	template <typename T>
	void	printPair(const T &lst);
};

#endif
