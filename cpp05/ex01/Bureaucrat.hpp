#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;
public:
	Bureaucrat(std::string name = "Default", int grade = 150);
	~Bureaucrat(void);
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat	&operator=(const Bureaucrat &copy);

	std::string	getName(void) const;
	int			getGrade(void) const;
	void		setGrade(int newGrade);
	void		signForm(Form &form) const;
	Bureaucrat	&operator++(void);
	Bureaucrat	&operator--(void);
	Bureaucrat	operator++(int);
	Bureaucrat	operator--(int);

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

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &bureaucrat);

#endif
