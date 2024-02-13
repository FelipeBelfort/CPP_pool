#include "AForm.hpp"

AForm::AForm(std::string name, int gradeToSign, int gradeToExec) : _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec), _isSigned(false)
{
	if (gradeToExec > 150 || gradeToSign > 150)
		throw GradeTooLowException();
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
}

AForm::~AForm()
{
}

AForm::AForm(const AForm &copy) :  _name(copy.getName()), _gradeToSign(copy.getGradeToSign()), _gradeToExec(copy.getGradeToExec()), _isSigned(copy.getIsSigned())
{
}

AForm	&AForm::operator=(const AForm &copy)
{

	std::cout << copy.getName() << " can't be atributed to " << this->getName() << std::endl;
	return *this;
}

std::string	AForm::getName(void) const
{
	return this->_name;
}

bool	AForm::getIsSigned(void) const
{
	return this->_isSigned;
}

int		AForm::getGradeToSign(void) const
{
	return this->_gradeToSign;
}

int		AForm::getGradeToExec(void) const
{
	return this->_gradeToExec;
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeToSign())
		throw GradeTooLowException();
	else
		this->_isSigned = true;
}

void	AForm::tryToExec(const Bureaucrat &executor) const
{
	if (!this->getIsSigned())
		throw IsNotSignedException();
	if (this->getGradeToExec() < executor.getGrade())
		throw GradeTooLowException();
	this->execute(executor);
}

std::ostream &operator<<(std::ostream &stream, const AForm &form)
{
	stream << "form " << form.getName() << ", grade to be signed " << form.getGradeToSign();
	stream << ", grade to be executed " << form.getGradeToExec();
	stream << " and it's " << (form.getIsSigned() ? "already" : "not") << " signed.";
	return stream;
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return "The grade is too high.";
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return "The grade is too low.";
}

const char	*AForm::IsNotSignedException::what() const throw()
{
	return "The form is not signed.";
}
