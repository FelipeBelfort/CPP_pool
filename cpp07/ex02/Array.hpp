#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
private:
	T				*_lst;
	size_t			_size;
public:
	Array(void);
	Array(size_t size = 0) : _size(size)
	{
		_lst = new[size] T;
	}
	~Array();
	Array(const Array &copy) : _size(copy.size())
	{
		_lst = new[size] T;
		for (size_t i = 0; i < this->_size; i++)
		{
			
		}

	}

	Array &operator=(const Array &copy);
	Array &operator[](const unsigned int index);

	const size_t	size(void) const
	{
		return _size;
	}

	class IndexNotFoundException : public std::exception
	{
	public:

		const char *what() const throw()
		{
			return "Are you trying to do a segfault?";
		}
	};
};

Array::Array(/* args */)
{
}

Array::~Array()
{
}


#endif
