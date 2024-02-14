#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <algorithm>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator		iterator;
	typedef typename std::stack<T>::container_type::const_iterator	const_iterator;

	MutantStack() : std::stack<T>() {};
	MutantStack(const MutantStack &copy) : std::stack<T>(copy) {};
	virtual ~MutantStack() {};
	MutantStack &operator=(const MutantStack &copy)
	{
		if (this != &copy)
			std::stack<T>::operator=(copy);
		return *this;
	}

	iterator		begin()
	{
		return std::stack<T>::c.begin();
	}
	iterator		end()
	{
		return std::stack<T>::c.end();
	}
	const_iterator	begin() const
	{
		return std::stack<T>::c.begin();
	}
	const_iterator	end() const
	{
		return std::stack<T>::c.end();
	}
};


#endif


