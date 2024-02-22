#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv)
{
	this->fillContainer(argc, argv);

	this->printList(this->_unsorted_list);
	mergeList(this->_unsorted_list);
	// this->printList(this->_unsorted_list);
	this->insertList(this->_unsorted_list);
	// std::cout << std::endl;
	// this->printList(this->_sorted_list);
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

void	PmergeMe::insertList(t_pair &lst)
{
	// size_t				size = lst.size();
	std::list<int>::iterator	curr;
	std::list<int>::iterator	test;
	size_t	group_size = 2;
	size_t	size_tmp = 2;

	if (lst.front().first == -1)
	{
		lst.push_back(lst.front());
		lst.pop_front();
	}
	this->_sorted_list.push_back(lst.front().second);
	for (t_pair::iterator it = lst.begin(); it != lst.end(); it++)
	{
		if ((*it).first >= 0)
			this->_sorted_list.push_back((*it).first);
	}
	// printList(this->_sorted_list);
	printList(lst);



	curr = this->_sorted_list.begin();
	curr++;
	// this->_sorted_list.push_back(lst.front().first);
	for (t_pair::iterator it = lst.begin(); it != lst.end(); it++)
	{
		if (it != lst.begin())
			it--;
		std::list<std::pair<std::list<int>::iterator, t_pair::iterator> >	ptrs;
		while (size_tmp-- && curr != this->_sorted_list.end() && it != lst.end())
		{
			std::pair<std::list<int>::iterator, t_pair::iterator> bla;
			bla.first = ++curr;
			bla.second = ++it;
			ptrs.push_back(bla);
			std::cout << "\nptrs ==> tosort == " << (*bla.second).second << " end ptr == " << *bla.first << std::endl;
		}
		std::list<std::pair<std::list<int>::iterator, t_pair::iterator> >::reverse_iterator	end = ptrs.rbegin();
		for (std::list<std::pair<std::list<int>::iterator, t_pair::iterator> >::reverse_iterator	ptr = end; ptr != ptrs.rend(); ptr++)
		{
			std::cout << "\nbefore insert " << (*(*ptr).second).second << " to put before == " << *this->binarySearch((*(*ptr).second).second, this->_sorted_list.begin(), (*ptr).first) << std::endl;
			printList(this->_sorted_list);
			this->_sorted_list.insert(this->binarySearch((*(*ptr).second).second, this->_sorted_list.begin(), (*ptr).first), (*(*ptr).second).second);
			std::cout << "after insert " << std::endl;
			printList(this->_sorted_list);
			end++;
		}
		size_tmp = group_size;
		group_size = this->getGroupSize(size_tmp);
		ptrs.clear();
		if (it == lst.end())
			break;
		if (curr == this->_sorted_list.end())
			curr--;
			// this->_sorted_list.insert(this->binarySearch((*it).second, this->_sorted_list.begin(), curr), (*it).second);


		// std::cout << *this->binarySearch((*it).second, this->_sorted_list.begin(), this->_sorted_list.end()) << std::endl;
		// test = this->binarySearch((*it).second, this->_sorted_list.begin(), curr++);
	}
	// for (size_t i = 0; i < size; i++)
	// {
	// 	std::list<int>::iterator	beg = this->_sorted_list.begin();
	// }
	// for (size_t i = 0; i < 173; i++)
	// {

	// 	std::cout << "i => " << i << " result => " << this->getGroupSize(i) << std::endl;
	// }

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

	return nb == n1 ? n3 : 0;
	// return n3;
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
	mid = ita;
	step = std::distance(start, end) / 2;
	std::advance(mid, step);
	while (step > 1)
	{
		// step /= 2;
		step = std::distance(start, end);
		// std::advance(mid, step);
		if (nb < *mid)
		{
			end = mid;
			std::advance(mid, -(step / 2));
		}
		else
		{
			start = mid;
			std::advance(mid, step / 2);
		}
	}

	std::cout << "\ntest binary " << " ita " << *ita << " itb " << *itb << std::endl;
	std::cout << "nb => " << nb << " == start == " << *start << " == mid == " << *mid << " == end == " << *end << std::endl;
	return nb > *mid ? ++mid : mid;
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
