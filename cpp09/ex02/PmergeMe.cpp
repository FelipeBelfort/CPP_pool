#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv)
{
	this->fillContainer(argc, argv);

	this->printList(this->_unsorted_list);
	mergeList(this->_unsorted_list);
	this->printList(this->_unsorted_list);
}

PmergeMe::~PmergeMe()
{

}


void	PmergeMe::fillContainer(int argc, char **argv)
{
	long long int	tmp;
	std::string		str;

	for (int i = 1; i < argc; i++)
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
		makePairList(tmp);
	}
}

void	PmergeMe::printList(const std::list<int> &lst)
{
	for (std::list<int>::const_iterator	it = lst.begin(); it != lst.end(); it++)
	{
		std::cout << " ==>  " << *it;
	}
	std::cout << std::endl;
}

void	PmergeMe::printList(const t_pair &lst)
{
	for (t_pair::const_iterator it = lst.begin(); it != lst.end(); it++)
	{
		std::cout << " ==>  " << (*it).first << " | " << (*it).second;
	}
	std::cout << std::endl;
}

void	PmergeMe::makePairList(int nb)
{
	std::pair<int, int>	pair;

	pair.first = -1;
	pair.second = -1;
	if (!this->_unsorted_list.size() || (this->_unsorted_list.back().first != -1))
	{
		pair.second = nb;
		this->_unsorted_list.push_back(pair);
		return;
	}
	if (nb > this->_unsorted_list.back().second)
		this->_unsorted_list.back().first = nb;
	else
	{
		this->_unsorted_list.back().first = this->_unsorted_list.back().second;
		this->_unsorted_list.back().second = nb;
	}
}

void	PmergeMe::mergeList(t_pair &lst)
{
	size_t				size;
	t_pair				lst2;
	t_pair::iterator	it;

	if (lst.size() == 1)
		return;
	size = lst.size() / 2;
	it = lst.begin();
	for (size_t i = 0; i < size; i++)
		it++;
	lst2.splice(lst2.end(), lst, it, lst.end());
	this->mergeList(lst);
	this->mergeList(lst2);
	lst.merge(lst2);
}

// static std::vector<int>	&splitVector(std::vector<int> &vec_a)
// {
// 	size_t						size = vec_a.size() / 2;
// 	std::vector<int>			vec_b;
// 	std::vector<int>::iterator	it = vec_a.begin();

// 	for (size_t i = 0; i < size; i++)
// 		it++;

// 	vec_b.insert(vec_b.begin(), it, vec_a.end());
// 	vec_a.erase(it, vec_a.end());

// 	return vec_b;
// }

// static std::vector<int>	&mergeVector(std::vector<int> &vec_a, std::vector<int> &vec_b)
// {
// 	if (vec_a.empty())
// 		return vec_b;
// 	if (vec_b.empty())
// 		return vec_a;
// 	if (vec_a)

// }

// template <typename T>
// void	PmergeMe::sortList(std::vector<T> unsorted)
// {
// 	std::vector<T>	sorted;
// 	size_t			size = unsorted.size();

// 	size -= size % 2;
// 	for (size_t i = 0; i < size; i++)
// 	{
// 		std::pair<T, T>	pair;
// 		if (unsorted[i] < unsorted[i + 1])
// 		{
// 			pair.first = unsorted[i];
// 			pair.second = unsorted[i + 1];
// 		}
// 		else
// 		{
// 			pair.first = unsorted[i + 1];
// 			pair.first = unsorted[1];
// 		}
// 	}

// }


/***
 *	criar pares
 *
 *	merge maiores
 *
 * insert menores
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
