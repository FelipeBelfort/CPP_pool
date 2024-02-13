#include "Bureaucrat.hpp"

int main() {
    // Create a Bureaucrat with a name and a grade
    Bureaucrat bureaucrat("John", 50);

    // Display the information of the Bureaucrat
    std::cout << "Initial Bureaucrat:\n" << bureaucrat << std::endl;

    // Increment and decrement the grade
    ++bureaucrat;
    bureaucrat++;
    ++bureaucrat;
    ++bureaucrat;
    ++bureaucrat;
    ++bureaucrat;
    ++bureaucrat;
    ++bureaucrat;
    std::cout << "After increment: " << bureaucrat << std::endl;

    --bureaucrat;
    bureaucrat--;
    std::cout << "After decrement: " << bureaucrat << std::endl;

    // Try to set a too high grade, should throw GradeTooHighException
    bureaucrat.setGrade(0);

    // Try to set a too low grade, should throw GradeTooLowException
    bureaucrat.setGrade(200);

    return 0;
}
