#include "PmergeMe.hpp"

template <typename T>
static bool	is_sorted(T lst)
{
	int	old = *lst.begin();
	for (typename T::iterator i = ++lst.begin(); i != lst.end(); i++)
	{
		if (old > *i)
			return false;
			// return (std::cout << old << " > " << *i, false);
		old = *i;
	}
	return true;
}

PmergeMe::PmergeMe(int argc, char **argv) : _time_init(0), _time_list(0)
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

void	PmergeMe::putTime(double &type)
{
	type = this->getTime() - type;
}

double	PmergeMe::getTime(void)
{
	struct timeval currentTime;
	gettimeofday(&currentTime, NULL);
	return (currentTime.tv_sec * 1000 + currentTime.tv_usec * 0.0001);
}

void	PmergeMe::fillContainer(int argc, char **argv)
{
	long long int	tmp;
	std::string		str;

	if (argc == 1)
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
		// if (argc == 2)
		// 	throw InputErrorException() ;
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

// void	PmergeMe::printList(const std::vector<int> &vec)
// {
// 	for (std::vector<int>::const_iterator	it = vec.begin(); it != vec.end(); it++)
// 	{
// 		std::cout << " " << *it;
// 	}
// 	std::cout << std::endl;
// }

template <typename T>
void	PmergeMe::printList(const T &lst)
{
	for (typename T::const_iterator	it = lst.begin(); it != lst.end(); it++)
	{
		std::cout << " " << *it;
	}
	std::cout << std::endl;
}

template <typename T>
void	PmergeMe::printPair(const T &lst)
{
	for (typename T::const_iterator it = lst.begin(); it != lst.end(); it++)
	{
		std::cout << " ==>  " << (*it).first << " | " << (*it).second; // << std::endl;
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
	size_t				size;
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
	// this->putTime(this->_time_list);
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
	// this->putTime(this->_time_list);
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
		group_size = this->getGroupSize(size_tmp, SIZE);
	}
}

size_t	PmergeMe::getGroupSize(size_t nb, size_t type)
{
	size_t	n1 = 0;
	size_t	n2 = type;
	size_t	n3 = type;

	if (nb < type)
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

template <typename T>
T	PmergeMe::binarySearchVec(int nb, T ita, T itb)
{
	size_t		step;
	T	start;
	T	mid;
	T	end;

	if (nb < (*ita).first)
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
		if (nb < (*mid).first)
			end = mid;
		else
			start = mid;
	}
	if (nb > (*mid).first && mid != itb)
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
	size_t					size;
	t_pair_vec				vec2;
	t_pair_vec				vec3;
	// t_pair_vec::iterator	it;

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

	// it = vec.begin();
	// std::advance(it, size / 2);
	// vec2.splice(vec2.end(), vec, it, vec.end());

}

void	PmergeMe::sortVector(void)
{
	// this->putTime(this->_time_vector);
	for (size_t i = 0; i < this->_original.size(); i++)
		makePairVector(this->_original[i]);
	// printPair(this->_unsorted_vector);
	// std::cout << this->_unsorted_vector.size();
	// DEBUG
	this->mergeVector(this->_unsorted_vector);
	if (this->_unsorted_vector.front().first == -1)
	{
		this->_unsorted_vector.push_back(this->_unsorted_vector.front());
		this->_unsorted_vector.erase(this->_unsorted_vector.begin());
	}
	// printPair(this->_unsorted_vector);
	// this->_sorted_vector.push_back(this->_unsorted_vector.front().second);
	for (t_pair_vec::iterator it = this->_unsorted_vector.begin(); it != this->_unsorted_vector.end(); it++)
		if ((*it).first >= 0)
			this->_sorted_vector.push_back((*it).first);
	this->_sorted_vector.reserve(this->_original.size());
	this->_unsorted_vector.reserve(this->_original.size() + 1);
	this->insertVector();
	// printList(this->_sorted_vector);
	// this->putTime(this->_time_vector);
}

template <typename T>
void	PmergeMe::pushPair(T it, int i)
{
	std::pair<int, int>		pair;
	// t_pair_vec::iterator	upper;

	pair.first = (*it).second;
	pair.second = -i - 1;
	(*it).second = -i - 1;
	if ((*it).first != -1)
		this->_unsorted_vector.insert(binarySearchVec(pair.first, this->_unsorted_vector.begin(), it), pair);
	else
	{
		this->_unsorted_vector.pop_back();
		this->_unsorted_vector.insert(binarySearchVec(pair.first, this->_unsorted_vector.begin(), this->_unsorted_vector.end()), pair);
	}
}

// void	PmergeMe::insertVector(void)
// {
// 	size_t	size = this->_unsorted_vector.size();
// 	size_t						group_size1 = 2;
// 	size_t						group_size2 = 2;
// 	size_t	tot_inserted = 0;
// 	size_t i = 0;

// 	this->_sorted_vector.insert(this->_sorted_vector.begin() + tot_inserted++, this->_unsorted_vector[0].second);
// 	while (tot_inserted < size)
// 	{
// 		size_t	size_tmp = i + group_size1 < size ? group_size1 : size - i - 1;
// 		i += size_tmp;
// 		for (size_t j = 0; j < size_tmp; j++)
// 		{
// 			int	nb = this->_unsorted_vector[i - j].second;
// 			std::vector<int>::iterator	it = this->_sorted_vector.begin() + (tot_inserted);
// 			if (*it != this->_unsorted_vector[i - j].first)
// 				--it;
// 			it = this->binarySearch(nb, this->_sorted_vector.begin(), it);
// 			this->_sorted_vector.insert(it, nb);
// 			tot_inserted++;
// 		}
// 		group_size1 = group_size2;
// 		group_size2 = this->getGroupSize(group_size1);
// 	}
// }

void	PmergeMe::insertVector(void)
{
	// V3
	size_t	size = this->_unsorted_vector.size();
	size_t						group_size1 = 2;
	size_t						group_size2 = 2;
	// size_t						size_tmp = 2;
	size_t	tot_inserted = 0;


	// for (size_t i = 1; i < size; i++)
	// {
	// 	*this->_unsorted_vector[i].second
	// }
	// while (++tot_inserted < size)
	this->_sorted_vector.insert(this->_sorted_vector.begin() + tot_inserted++, this->_unsorted_vector[0].second);
	size_t i = 0;
	while (tot_inserted < size)
	{
		size_t	size_tmp = i + group_size1 < size ? group_size1 : size - i - 1;
		i += size_tmp;
			// int n = 0;
			std::vector<int>::iterator	it = this->_sorted_vector.begin() + (i + tot_inserted);
			std::vector<int>::iterator	prev = it - 1;
		for (size_t j = 0; j < size_tmp; j++)
		{
			int	nb = this->_unsorted_vector[i - j].second;
			// std::vector<int>::iterator	it = this->_sorted_vector.begin() + (i - j + tot_inserted);
			// std::vector<int>::iterator	it = prev;
			// if (*prev != this->_unsorted_vector[i - j].first)
			// 	--prev;
			// else
			// 	it = prev; //--; prev--;
				// it = prev--;

			if (*it != this->_unsorted_vector[i - j].first && this->_unsorted_vector[i - j].first != -1)
				it--;
			prev = it;
			// 	it = prev;
			// 	it = this->_sorted_vector.begin() + (j + tot_inserted);
				// --it;
			// else
			// 	n = 0;//-= n <= 1 ? 0 : 1;
			// --prev;
			std::vector<int>::iterator	it2 = it;
			it = this->binarySearch(nb, this->_sorted_vector.begin(), it2);
			// if (*it2 != this->_unsorted_vector[i - j].first)
			// 	std::cout << "\nindex = " << i - j << " nb = " << nb << " put before = " << *it << " i in sorted = " << _sorted_vector[i - j + 1] << " i in unsorted = " << this->_unsorted_vector[i - j].first << " sorted com tot = " << *it2 << " sorted++ = " << *(it2 + 1) << " sorted-- = " << *(it2 - 1) << " tot_inserted = " << tot_inserted << std::endl << std::endl;
				// std::cout << "\nbefore insert nb = " << nb << " in pair with = " << this->_unsorted_vector[i - j].first << "\nprev-- = " << *(prev - 1) << " prev = " << *prev << " prev++ = " << *(prev + 1) << std::endl;
			this->_sorted_vector.insert(it, nb);
				// std::cout << "\nafter insert nb = " << nb << "\nprev-- = " << *(prev - 1) << " prev = " << *prev << " prev++ = " << *(prev + 1) << std::endl;
			tot_inserted++;
				it = prev--;
			// if (*prev == this->_unsorted_vector[i - j - 1].first)
			// else
			// 	prev--;
			// if (*(prev--) != this->_unsorted_vector[i - j - 1].first)
			// {
			// 	--prev;
			// 	n = 0;
			// }
			// else
			// 	n++;
			// n++;
	// std::cout << "\n";
	// printList(this->_sorted_vector);
	// printPair(this->_unsorted_vector);
		}


		// tot_inserted += n;
		// tot_inserted += size_tmp;

		group_size1 = group_size2;
		group_size2 = this->getGroupSize(group_size1, SIZE);
	}

	// while (--size > 1)
	// {
	// 	//
	// 	/**
	// 	 *procurar o ultimo do grupo
	// 	 *inserir antes do begin() + tot_inserted + index
	// 	 *voltar 1 enquanto ainda estiver no grupo
	// 	 * begin() + tot_inserted + index != alvo ? begin() + tot_inserted + index + n++ : n = 0
	// 	 *
	// 	 *
	// 	 *
	// 	*/
	// 	int	nb = this->_unsorted_vector[size].second;
	// 	std::vector<int>	tmp = this->_sorted_vector;
	// 	std::vector<int>::iterator	it = this->binarySearch(nb, tmp.begin(), tmp.begin() + tmp.size());
	// 	std::cout << "\nindex = " << size << " nb = " << nb << " put before = " << *it << " i in sorted = " << tmp[size] << " i in unsorted = " << this->_unsorted_vector[size].first << " tot_inserted = " << tot_inserted++ << std::endl << std::endl;
	// 	tmp.insert(it, nb);
	// 	printList(tmp);
	// 	printPair(this->_unsorted_vector);
	// }









	// V2
	// size_t						group_size = 2;
	// size_t						size_tmp = 2;
	// int							vec_size = this->_unsorted_vector.size() - 1;

	// 	printPair(this->_unsorted_vector);
	// this->pushPair(this->_unsorted_vector.begin(), 0);
	// while (vec_size >= 1)
	// {
	// 	// std::cout << "\nvec_size before => " << vec_size << std::endl;
	// 	t_pair_vec::iterator	it = this->_unsorted_vector.begin();
	// 	while (++it != this->_unsorted_vector.end() && (*it).second <= 0)
	// 		;
	// 		// it++;
	// 	size_t	i = 0;
	// 	while (++it != this->_unsorted_vector.end() && i++ < size_tmp)
	// 		;
	// 		// it++;
	// 	while (it != this->_unsorted_vector.begin() && size_tmp)
	// 	{
	// 		if ((*it).second >= 0 && it != this->_unsorted_vector.end())
	// 		{
	// 	std::cout << "\nbefore insert => " << (*it).second << " | size_tmp = " << size_tmp << "\n" << std::endl;
	// 	printPair(this->_unsorted_vector);
	// 			this->pushPair(it, size_tmp);
	// 			vec_size--;
	// 			size_tmp--;
	// 		}
	// 		--it;
	// 	}
	// 	std::cout << " size_tmp after loop = " << size_tmp << std::endl;
	// 	// std::cout << "\nvec_size after => " << vec_size << std::endl << std::endl;
	// 	if (it == this->_unsorted_vector.end())
	// 		break;
	// 	size_tmp = group_size;
	// 	group_size = this->getGroupSize(size_tmp);

	// }
	// 	std::cout << "\nend of insert =>\n";
	// 	printPair(this->_unsorted_vector);







	// V1
	// size_t						group_size = 2;
	// size_t						size_tmp = 2;
	// std::vector<int>::iterator	curr = ++this->_sorted_vector.begin();
	// t_pair_vec::iterator 		it = this->_unsorted_vector.begin();

	// printPair(this->_unsorted_vector);
	// while (it != this->_unsorted_vector.end())
	// {
	// 	std::vector<t_insert_vec>	ptrs;
	// 	while (curr != this->_sorted_vector.end() && size_tmp--)
	// 	{
	// 		if (++it == this->_unsorted_vector.end())
	// 			break;
	// 		t_insert_vec	tmp;
	// 		tmp.first = ++curr;
	// 		tmp.second = (*it).second;
	// 		ptrs.push_back(tmp);
	// 		std::cout << " it(nb) => " << tmp.second << " curr => " << *tmp.first << std::endl;
	// 		if (curr == this->_sorted_vector.end())
	// 			curr--;
	// 	}
	// 	for (std::vector<t_insert_vec>::reverse_iterator	ptr = ptrs.rbegin(); ptr != ptrs.rend(); ptr++)
	// 	{
	// 		size_t	nb = (*ptr).second;
	// 		std::vector<int>::iterator	test = this->binarySearch(nb, this->_sorted_vector.begin(), (*ptr).first);
	// 		std::cout << "nb => " << nb << " to insert before => " << *test << std::endl;
	// printList(this->_sorted_vector);
	// 		this->_sorted_vector.insert(this->binarySearch(nb, this->_sorted_vector.begin(), (*ptr).first), nb);
	// 	}
	// 	size_tmp = group_size;
	// 	group_size = this->getGroupSize(size_tmp);
	// }
}

const char	*PmergeMe::InputErrorException::what() const throw()
{
	return "Error";
}
