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

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream &operator<<(std::ostream &stream, const Fixed &fixed);

#endif