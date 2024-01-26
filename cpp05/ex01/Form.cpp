#include "Form.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExec) : _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec), _isSigned(false)
{
	if (gradeToExec > 150 || gradeToSign > 150)
		throw GradeTooLowException();
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
}

Form::~Form()
{
}

Form::Form(const Form &copy) :  _name(copy.getName()), _gradeToSign(copy.getGradeToSign()), _gradeToExec(copy.getGradeToExec()), _isSigned(copy.getIsSigned())
{
}

Form	&Form::operator=(const Form &copy)
{
	std::cout << "A form can't be atributed to another." << std::endl;
	return *this;
}

std::string	Form::getName(void) const
{
	return this->_name;
}

bool	Form::getIsSigned(void) const
{
	return this->_isSigned;
}

int		Form::getGradeToSign(void) const
{
	return this->_gradeToSign;
}

int		Form::getGradeToExec(void) const
{
	return this->_gradeToExec;
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeToSign())
		throw GradeTooLowException();
	else
		this->_isSigned = true;
}

std::ostream &operator<<(std::ostream &stream, const Form &form)
{
	stream << "Form " << form.getName() << ", grade to be signed " << form.getGradeToSign();
	stream << ", grade to be executed " << form.getGradeToExec();
	stream << " and it's " << (form.getIsSigned() ? "already" : "not") << " signed.";
	return stream;
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return "The grade is too high.";
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return "The grade is too low.";
}
