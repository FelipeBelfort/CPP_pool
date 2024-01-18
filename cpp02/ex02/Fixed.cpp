#include "Fixed.hpp"

Fixed::Fixed(void): _value(0)
{
	std::cout << "Fixed object created with default constructor" << std::endl;
}

Fixed::Fixed(const int nb_int): _value(nb_int << _fractional)
{
	std::cout << "Fixed object created with Int constructor" << std::endl;
}

Fixed::Fixed(const float nb_float): _value((int)roundf(nb_float * (1 << _fractional)))
{
	std::cout << "Fixed object created with Float constructor" << std::endl;
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

float	Fixed::toFloat(void) const
{
	return float(this->_value) / (1 << _fractional);
}

int	Fixed::toInt(void) const
{
	return (this->_value >> _fractional);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	return (a.getRawBits() < b.getRawBits() ? a : b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	return (a.getRawBits() > b.getRawBits() ? a : b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a.getRawBits() < b.getRawBits() ? a : b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a.getRawBits() > b.getRawBits() ? a : b);
}


std::ostream &operator<<(std::ostream &stream, const Fixed &fixed)
{
	stream << fixed.toFloat();
	return stream;
}

bool	Fixed::operator>(const Fixed &fixed)
{
	return this->_value > fixed._value;
}

bool	Fixed::operator<(const Fixed &fixed)
{
	return this->_value < fixed._value;
}

bool	Fixed::operator<=(const Fixed &fixed)
{
	return this->_value <= fixed._value;
}

bool	Fixed::operator>=(const Fixed &fixed)
{
	return this->_value >= fixed._value;
}

bool	Fixed::operator==(const Fixed &fixed)
{
	return this->_value == fixed._value;
}

bool	Fixed::operator!=(const Fixed &fixed)
{
	return this->_value != fixed._value;
}

Fixed	Fixed::operator+(const Fixed &fixed)
{
	Fixed	result;

	result.setRawBits(this->getRawBits() + fixed.getRawBits());
	return result;
}

Fixed	Fixed::operator-(const Fixed &fixed)
{
	Fixed	result;

	result.setRawBits(this->getRawBits() - fixed.getRawBits());
	return result;
}

Fixed	Fixed::operator*(const Fixed &fixed)
{
	Fixed	result;

	result.setRawBits(this->getRawBits() * fixed.getRawBits() >> this->_fractional);
	return result;
}

Fixed	Fixed::operator/(const Fixed &fixed)
{
	Fixed	result;

	result.setRawBits((this->getRawBits() * (1 << this->_fractional)) / fixed.getRawBits());
	return result;
}

Fixed&	Fixed::operator++(void)
{
	this->_value += 1;
	return *this;
}

Fixed&	Fixed::operator--(void)
{
	this->_value -= 1;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp;
	tmp = *this;
	this->_value += 1;
	return tmp;
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp;
	tmp = *this;
	this->_value -= 1;
	return tmp;
}

