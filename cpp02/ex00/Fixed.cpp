#include "Fixed.hpp"

Fixed::Fixed(void): _value(0)
{
	std::cout << "Fixed object created with default constructor" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Fixed object destroyed" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Fixed object copied" << std::endl;
	*this = copy;
}

Fixed	&Fixed::operator=(const Fixed &copy)
{
	if (this != &copy)
	{
		std::cout << "Assignment operator called" << std::endl;
		this->_value = copy.getRawBits();
	}
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(const int raw)
{
	this->_value = raw;
}
