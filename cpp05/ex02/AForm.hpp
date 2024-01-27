#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	const int			_gradeToSign;
	const int			_gradeToExec;
	bool				_isSigned;
public:
	AForm(std::string name, int gradeToSign, int gradeToExec);
	virtual ~AForm(void);
	AForm(const AForm &copy);
	AForm	&operator=(const AForm &copy);

	std::string	getName(void) const;
	int			getGradeToSign(void) const;
	int			getGradeToExec(void) const;
	bool		getIsSigned(void) const;
	void		beSigned(const Bureaucrat &bureaucrat);
	virtual void	Execute(const Bureaucrat &executor) const = 0;


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

std::ostream &operator<<(std::ostream &stream, const AForm &form);

#endif
