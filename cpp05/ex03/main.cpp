#include "Intern.hpp"

static void testForm(Bureaucrat* bur, AForm* form)
{
    std::cout << "\nSign test" << std::endl;
    bur->signForm(*form);
    std::cout << "Execute test" << std::endl;
    bur->executeForm(*form);
}

int main()
{
    Intern test;
    AForm* shrub = Intern::alsoMakeForm("ShrubberyCreationForm", "ChezMoi");;
    AForm* robot = Intern::alsoMakeForm("RobotomyRequestForm", "You");
    AForm* pardon = test.makeForm("PresidentialPardonForm", "No one");
    AForm* test2 = test.makeForm("blablabla", "No one");

    std::cout << "empty test --> " << test2 << std::endl;

    Bureaucrat* bur1 = new Bureaucrat("bur1", 120);
    Bureaucrat* bur2 = new Bureaucrat("bur2", 35);
    Bureaucrat* bur3 = new Bureaucrat("bur3", 5);

    std::cout << *shrub << "\n" << *robot << "\n" << *pardon << "\n" << *bur1 << "\n" << *bur2 << "\n" << *bur3 << std::endl;

    testForm(bur1, shrub);
    testForm(bur1, pardon);
    testForm(bur1, robot);
    testForm(bur2, robot);
    testForm(bur3, pardon);


    for (int i = bur1->getGrade(); i > pardon->getGradeToExec(); i--)
        (*bur1)++;

    testForm(bur1, pardon);
    testForm(bur3, pardon);


    delete shrub;
    delete robot;
    delete pardon;

    delete bur1;
    delete bur2;
    delete bur3;

    return (0);
}
