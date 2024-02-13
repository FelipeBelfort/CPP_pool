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
	Array(size_t size = 0) : _lst(new T[size]), _size(size)
	{
	}

	~Array()
	{
		delete [] this->_lst;
	}

	Array(const Array &copy) : _lst(NULL)
	{
		*this = copy;
	}

	Array &operator=(const Array &copy)
	{
		if (this == &copy)
			return *this;
		if (_lst)
			delete [] _lst;
		_lst = new T[copy.size()];
		this->_size = copy.size();
		for (size_t i = 0; i < this->_size; i++)
			_lst[i] = copy._lst[i];
		return *this;
	}

	T &operator[](const unsigned int index)
	{
		if (index >= this->_size)
			throw IndexNotFoundException();
		return this->_lst[index];
	}

	T const & operator[](const unsigned int index) const
	{
		if (index >= this->_size)
			throw IndexNotFoundException();
		return this->_lst[index];
	}

	size_t	size(void) const
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

#endif








// # include <iostream>
// # include <algorithm>

// /**
//  * @brief Exception NotFound.
//  */
// class NotFound : public std::exception
// {
//     virtual const char* what() const throw() { return ("Not found."); }
// };

// /**
//  * @brief Get the first occurence of an integer in
//  * a integer container.
//  *
//  * @param t is the integer container.
//  * @param n is the integer to found.
//  *
//  * @throw a NotFound exception if the integer is not
//  * in the container.
//  */
// template < template < typename , typename> class T>
// typename T<int, std::allocator<int> >::iterator
//     easyfind(T<int, std::allocator<int> > &array, int n)
// {
//     typename T<int, std::allocator<int> >::iterator itpos;
//     if ((itpos = std::find(array.begin(), array.end(), n)) != array.end())
//         return (itpos);
//     else
//         throw NotFound();
// }
