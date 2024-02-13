#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>

class RobotomyRequestForm : public AForm
{
private:
	std::string	_target;
public:
	RobotomyRequestForm(std::string target = "corrector");
	~RobotomyRequestForm(void);
	RobotomyRequestForm(const RobotomyRequestForm &copy);
	RobotomyRequestForm	&operator=(const RobotomyRequestForm &copy);

	std::string	getTarget(void) const;
	void		setTarget(std::string newTarget);
	void		execute(const Bureaucrat &executor) const;
};

#endif
