#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <vector>
# include <iostream>

template <typename T>
void	easyfind(T container, int index)
{
	typename T::iterator	it;

	it = std::find(container.begin(), container.end(), index);
	if (it != container.end())
		std::cout << "Value found: " << *it << std::endl;
	else
		std::cout << "Value not found" << std::endl;
}


#endif

