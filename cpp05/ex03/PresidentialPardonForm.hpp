#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string	_target;
public:
	PresidentialPardonForm(std::string target = "fbelfort");
	~PresidentialPardonForm(void);
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	PresidentialPardonForm	&operator=(const PresidentialPardonForm &copy);

	std::string	getTarget(void) const;
	void		setTarget(std::string newTarget);
	void		execute(const Bureaucrat &executor) const;
};

#endif
