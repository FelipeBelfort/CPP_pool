#include "Bureaucrat.hpp"

int main() {
    try {
        // Create a Bureaucrat with a name and a grade
        Bureaucrat bureaucrat("John", 50);

        // Display the information of the Bureaucrat
        std::cout << "Initial Bureaucrat:\n" << bureaucrat << std::endl;

        // Increment and decrement the grade
        ++bureaucrat;
        std::cout << "After increment: " << bureaucrat << std::endl;

        --bureaucrat;
        std::cout << "After decrement: " << bureaucrat << std::endl;

        // Try to set a too high grade, should throw GradeTooHighException
        bureaucrat.setGrade(10);

        // Try to set a too low grade, should throw GradeTooLowException
        bureaucrat.setGrade(200);
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "General exception caught: " << e.what() << std::endl;
    }

    try {
        // Try creating a Bureaucrat with a too high grade, should throw GradeTooLowException
        Bureaucrat highGradeBureaucrat("Alice", 0);
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "General exception caught: " << e.what() << std::endl;
    }

    try {
        // Try creating a Bureaucrat with a too low grade, should throw GradeTooHighException
        Bureaucrat lowGradeBureaucrat("Bob", 151);
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "General exception caught: " << e.what() << std::endl;
    }

    return 0;
}
