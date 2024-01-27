#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	this->setGrade(grade);
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy.getName())
{
	*this = copy;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy)
{
	this->setGrade(copy.getGrade());
	return *this;
}

std::string	Bureaucrat::getName(void) const
{
	return this->_name;
}

int			Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

void	Bureaucrat::setGrade(int newGrade)
{
	try
	{
		if (newGrade < 1)
		{
			this->_grade = 1;
			throw Bureaucrat::GradeTooHighException();
		}
		else if (newGrade > 150)
		{
			this->_grade = 150;
			throw Bureaucrat::GradeTooLowException();
		}
		else
			this->_grade = newGrade;
	}
	catch(const Bureaucrat::GradeTooHighException e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	Bureaucrat::signAForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed form " << form.getName() << std::endl;
	}
	catch(const AForm::GradeTooLowException &e)
	{
		std::cout << this->getName() << " couldn’t sign form " << form.getName() << " because " << e.what() << std::endl;
	}

}

void	Bureaucrat::executeForm(const AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed form " << form.getName() << std::endl;
	}
	catch(const AForm::GradeTooLowException &e)
	{
		std::cout << this->getName() << " couldn’t sign form " << form.getName() << " because " << e.what() << std::endl;
	}

}

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &bureaucrat)
{
	stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return stream;
}

Bureaucrat&	Bureaucrat::operator++(void)
{
	this->setGrade(this->getGrade() - 1);
	return *this;
}

Bureaucrat&	Bureaucrat::operator--(void)
{
	this->setGrade(this->getGrade() + 1);
	return *this;
}

Bureaucrat	Bureaucrat::operator++(int)
{
	Bureaucrat	tmp(*this);
	this->setGrade(this->getGrade() - 1);
	return tmp;
}

Bureaucrat	Bureaucrat::operator--(int)
{
	Bureaucrat	tmp(*this);
	this->setGrade(this->getGrade() + 1);
	return tmp;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return "The highest grade allowed is 1, that is your grade now.";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return "The lowest grade allowed is 150, that is your grade now.";
}
