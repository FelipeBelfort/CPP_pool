#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	const int			_gradeToSign;
	const int			_gradeToExec;
	bool				_isSigned;
public:
	Form(std::string name, int gradeToSign, int gradeToExec);
	~Form(void);
	Form(const Form &copy);
	Form	&operator=(const Form &copy);

	std::string	getName(void) const;
	int			getGradeToSign(void) const;
	int			getGradeToExec(void) const;
	bool		getIsSigned(void) const;
	void		beSigned(const Bureaucrat &bureaucrat);


	class GradeTooHighException : public std::exception
	{
	public:

		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:

		const char *what() const throw();
	};

};

std::ostream &operator<<(std::ostream &stream, const Form &form);

#endif
