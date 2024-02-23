#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv)
{
	double	test = getTime();
	this->fillContainer(argc, argv);

	this->sortList();
	// this->printList(this->_unsorted_list);
	// this->mergeList(this->_unsorted_list);
	// this->printList(this->_unsorted_list);
	// this->insertList(this->_unsorted_list);
	// std::cout << std::endl;
	if (!std::is_sorted(this->_sorted_list.begin(), _sorted_list.end()))
		this->printList(this->_sorted_list);
	else
		std::cout << "OK" << std::endl;
	std::cout << getTime() - test << std::endl;
}

PmergeMe::~PmergeMe()
{

}

double	PmergeMe::getTime(void)
{
	struct timeval currentTime;
	gettimeofday(&currentTime, NULL);
	// return ((currentTime.tv_sec * 1000000LL + currentTime.tv_usec) * 0.000001);
	return ((currentTime.tv_sec + currentTime.tv_usec) * 0.00001);
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
		if (argc == 2)
			return ;
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

	size = lst.size();
	if (size == 1)
		return;
	it = lst.begin();
	std::advance(it, size / 2);
	lst2.splice(lst2.end(), lst, it, lst.end());
	this->mergeList(lst);
	this->mergeList(lst2);
	lst.merge(lst2);
}

void	PmergeMe::sortList(void)
{
	this->mergeList(this->_unsorted_list);
	if (this->_unsorted_list.front().first == -1)
	{
		this->_unsorted_list.push_back(this->_unsorted_list.front());
		this->_unsorted_list.pop_front();
	}
	this->_sorted_list.push_back(this->_unsorted_list.front().second);
	for (t_pair::iterator it = this->_unsorted_list.begin(); it != this->_unsorted_list.end(); it++)
		if ((*it).first >= 0)
			this->_sorted_list.push_back((*it).first);
	this->insertList();
}

void	PmergeMe::insertList(void)
{
	size_t						group_size = 2;
	size_t						size_tmp = 2;
	std::list<int>::iterator	curr = ++this->_sorted_list.begin();
	t_pair::iterator 			it = this->_unsorted_list.begin();

	while (it != this->_unsorted_list.end())
	{
		std::list<t_insert_list>	ptrs;
		while (size_tmp-- && curr != this->_sorted_list.end() && it != this->_unsorted_list.end())
		{
			t_insert_list	tmp;
			tmp.first = ++curr;
			tmp.second = ++it;
			ptrs.push_back(tmp);
		}
		for (std::list<t_insert_list>::reverse_iterator	ptr = ptrs.rbegin(); ptr != ptrs.rend(); ptr++)
		{
			size_t	nb = (*(*ptr).second).second;
			this->_sorted_list.insert(this->binarySearch(nb, this->_sorted_list.begin(), (*ptr).first), nb);
		}
		size_tmp = group_size;
		group_size = this->getGroupSize(size_tmp);
		if (curr == this->_sorted_list.end())
			curr--;
	}
}

size_t	PmergeMe::getGroupSize(size_t nb)
{
	size_t	n1 = 0;
	size_t	n2 = 2;
	size_t	n3 = 2;

	if (nb < 2)
		return n3;
	do {
		n3 = n2 + n1 * 2;
		n1 = n2;
		n2 = n3;
	} while (n3 <= nb);

	return n3;
}

template <typename T>
T	PmergeMe::binarySearch(int nb, T ita, T itb)
{
	size_t	step;
	T		start;
	T		mid;
	T		end;

	if (nb < *ita)
		return ita;
	start = ita;
	end = itb;
	step = std::distance(start, end);
	while (step > 2)
	{
		step = std::distance(start, end);
		mid = start;
		std::advance(mid, step / 2);
		if (nb < *mid)
			end = mid;
		else
			start = mid;
	}
	return nb > *mid ? ++mid : mid;
}
