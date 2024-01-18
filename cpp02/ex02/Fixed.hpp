#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	private:
		int					_value;
		static const int	_fractional = 8;
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const int nb_int);
		Fixed(const float nb_float);
		Fixed(const Fixed &copy);
		Fixed	&operator=(const Fixed &copy);

		bool	operator>(const Fixed &fixed);
		bool	operator<(const Fixed &fixed);
		bool	operator<=(const Fixed &fixed);
		bool	operator>=(const Fixed &fixed);
		bool	operator==(const Fixed &fixed);
		bool	operator!=(const Fixed &fixed);

		Fixed	operator+(const Fixed &fixed);
		Fixed	operator-(const Fixed &fixed);
		Fixed	operator*(const Fixed &fixed);
		Fixed	operator/(const Fixed &fixed);

		Fixed&	operator++(void);
		Fixed&	operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);

		int				getRawBits(void) const;
		void			setRawBits(int const raw);
		float			toFloat(void) const;
		int				toInt(void) const;
		static Fixed&	min(Fixed& a, Fixed& b);
		static Fixed&	max(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);
};

std::ostream &operator<<(std::ostream &stream, const Fixed &fixed);

#endif