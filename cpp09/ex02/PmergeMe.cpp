#include "PmergeMe.hpp"

template <typename T>
static bool	is_sorted(T lst)
{
	int	old = *lst.begin();
	for (typename T::iterator i = ++lst.begin(); i != lst.end(); i++)
	{
		if (old > *i)
			return false;
		old = *i;
	}
	return true;
}

PmergeMe::PmergeMe(int argc, char **argv) : _time_init(0), _time_list(0), _time_vector(0)
{
	this->putTime(this->_time_init);
	this->fillContainer(argc, argv);
	if (is_sorted(this->_original))
	{
		std::cout << "Already sorted." << std::endl;
		return;
	}
	this->putTime(this->_time_init);

	this->putTime(this->_time_list);
	this->sortList();
	this->putTime(this->_time_list);

	this->putTime(this->_time_vector);
	this->sortVector();
	this->putTime(this->_time_vector);
	
	this->printResult();
	if (is_sorted(this->_sorted_list))
		std::cout << "List: OK" << std::endl;
	else
		std::cout << "List: KO" << std::endl;
	if (is_sorted(this->_sorted_vector))
		std::cout << "Vector: OK" << std::endl;
	else
		std::cout << "Vector: KO" << std::endl;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	*this = copy;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &copy)
{
	if (this != &copy)
	{
		this->_original = copy._original;
		this->_unsorted_list = copy._unsorted_list;
		this->_unsorted_vector = copy._unsorted_vector;
		this->_sorted_list = copy._sorted_list;
		this->_sorted_vector = copy._sorted_vector;
		this->_time_init = copy._time_init;
		this->_time_list = copy._time_list;
		this->_time_vector = copy._time_vector;
	}
	return *this;
}

void	PmergeMe::putTime(double &type)
{
	type = this->getTime() - type;
}

double	PmergeMe::getTime(void)
{
	struct timeval currentTime;
	gettimeofday(&currentTime, NULL);
	return (currentTime.tv_sec * 1000 + currentTime.tv_usec * 0.00001);
}

void	PmergeMe::fillContainer(int argc, char **argv)
{
	long long int	tmp;
	std::string		str;

	if (argc <= 2)
		throw InputErrorException();
	for (int i = 1; i < argc; i++)
	{
		str = argv[i];
		tmp = atol(argv[i]);
		if (tmp < 0)
			throw InputErrorException() ;
		if (str.find_first_not_of("0123456789") != std::string::npos)
			throw InputErrorException();
		if (tmp > __INT_MAX__)
			throw InputErrorException();
		this->_original.push_back(tmp);
	}
}

void	PmergeMe::printResult(void)
{
	std::cout << "Before: ";
	printList(this->_original);
	std::cout << "After:  ";
	printList(this->_sorted_list);
	std::cout << "Time to process a range of  " << this->_sorted_list.size() << "  elements with std::list   :   " << this->_time_list + this->_time_init << std::endl;
	std::cout << "Time to process a range of  " << this->_sorted_vector.size() << "  elements with std::vector :   " << this->_time_vector + this->_time_init << std::endl;
}

template <typename T>
void	PmergeMe::printList(const T &lst)
{
	for (typename T::const_iterator	it = lst.begin(); it != lst.end(); it++)
	{
		std::cout << " " << *it;
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

void	PmergeMe::mergeList(t_pair_lst &lst)
{
	size_t					size;
	t_pair_lst				lst2;
	t_pair_lst::iterator	it;

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
	for (size_t i = 0; i < this->_original.size(); i++)
		makePairList(this->_original[i]);
	this->mergeList(this->_unsorted_list);
	if (this->_unsorted_list.front().first == -1)
	{
		this->_unsorted_list.push_back(this->_unsorted_list.front());
		this->_unsorted_list.pop_front();
	}
	this->_sorted_list.push_back(this->_unsorted_list.front().second);
	for (t_pair_lst::iterator it = this->_unsorted_list.begin(); it != this->_unsorted_list.end(); it++)
		if ((*it).first >= 0)
			this->_sorted_list.push_back((*it).first);
	this->insertList();
}

void	PmergeMe::insertList(void)
{
	size_t						group_size = 2;
	size_t						size_tmp = 2;
	std::list<int>::iterator	curr = ++this->_sorted_list.begin();
	t_pair_lst::iterator 			it = this->_unsorted_list.begin();

	while (it != this->_unsorted_list.end())
	{
		std::list<t_insert_list>	ptrs;
		while (curr != this->_sorted_list.end() && size_tmp--)
		{
			if (++it == this->_unsorted_list.end())
				break;
			t_insert_list	tmp;
			tmp.first = ++curr;
			tmp.second = (*it).second;
			ptrs.push_back(tmp);
			if (curr == this->_sorted_list.end())
				curr--;
		}
		for (std::list<t_insert_list>::reverse_iterator	ptr = ptrs.rbegin(); ptr != ptrs.rend(); ptr++)
		{
			size_t	nb = (*ptr).second;
			this->_sorted_list.insert(this->binarySearch(nb, this->_sorted_list.begin(), (*ptr).first), nb);
		}
		size_tmp = group_size;
		group_size = this->getGroupSize(size_tmp);
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
T	PmergeMe::binarySearch(int nb, const T &ita, const T &itb)
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
	mid = end;
	while (step > 1)
	{
		step = std::distance(start, end);
		mid = start;
		std::advance(mid, step / 2);
		if (nb < *mid)
			end = mid;
		else
			start = mid;
	}
	if (nb > *mid && mid != itb)
		mid++;
	return mid;
}

void	PmergeMe::makePairVector(int nb)
{
	std::pair<int, int>	pair;

	pair.first = -1;
	pair.second = -1;
	if (!this->_unsorted_vector.size() || (this->_unsorted_vector.back().first != -1))
	{
		pair.second = nb;
		this->_unsorted_vector.push_back(pair);
		return;
	}
	if (nb > this->_unsorted_vector.back().second)
		this->_unsorted_vector.back().first = nb;
	else
	{
		this->_unsorted_vector.back().first = this->_unsorted_vector.back().second;
		this->_unsorted_vector.back().second = nb;
	}
}

void	PmergeMe::mergeVector(t_pair_vec &vec)
{
	size_t		size;
	t_pair_vec	vec2;
	t_pair_vec	vec3;

	size = vec.size();
	if (size > 1)
	{
		for (size_t i = 0; i < size; i++)
		{
			if (i < size / 2)
				vec2.push_back(vec[i]);
			else
				vec3.push_back(vec[i]);
		}

		this->mergeVector(vec2);
		this->mergeVector(vec3);
		std::merge(vec2.begin(), vec2.end(), vec3.begin(), vec3.end(), vec.begin());
	}
}

void	PmergeMe::sortVector(void)
{
	for (size_t i = 0; i < this->_original.size(); i++)
		makePairVector(this->_original[i]);
	this->mergeVector(this->_unsorted_vector);
	if (this->_unsorted_vector.front().first == -1)
	{
		this->_unsorted_vector.push_back(this->_unsorted_vector.front());
		this->_unsorted_vector.erase(this->_unsorted_vector.begin());
	}
	for (t_pair_vec::iterator it = this->_unsorted_vector.begin(); it != this->_unsorted_vector.end(); it++)
		if ((*it).first >= 0)
			this->_sorted_vector.push_back((*it).first);
	this->_sorted_vector.reserve(this->_original.size());
	this->_unsorted_vector.reserve(this->_original.size() + 1);
	this->insertVector();
}

void	PmergeMe::insertVector(void)
{
	size_t	size = this->_unsorted_vector.size();
	size_t	group_size1 = 2;
	size_t	group_size2 = 2;
	size_t	tot_inserted = 0;


	this->_sorted_vector.insert(this->_sorted_vector.begin() + tot_inserted++, this->_unsorted_vector[0].second);
	size_t i = 0;
	while (tot_inserted < size)
	{
		size_t	size_tmp = i + group_size1 < size ? group_size1 : size - i - 1;
		i += size_tmp;
			std::vector<int>::iterator	it = this->_sorted_vector.begin() + (i + tot_inserted);
			std::vector<int>::iterator	prev = it - 1;
		for (size_t j = 0; j < size_tmp; j++)
		{
			int	nb = this->_unsorted_vector[i - j].second;
			if (*it != this->_unsorted_vector[i - j].first && this->_unsorted_vector[i - j].first != -1)
				it--;
			prev = it;
			it = this->binarySearch(nb, this->_sorted_vector.begin(), it);
			this->_sorted_vector.insert(it, nb);
			tot_inserted++;
			it = prev--;
		}
		group_size1 = group_size2;
		group_size2 = this->getGroupSize(group_size1);
	}
}

const char	*PmergeMe::InputErrorException::what() const throw()
{
	return "Error";
}
