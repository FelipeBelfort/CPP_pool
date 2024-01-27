#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main() {
    try {
        // Creating a Bureaucrat and a AForm
        Bureaucrat bureaucrat("John", 41);
        AForm AForm("Document", 40, 30);

        // Displaying initial inAFormation
        std::cout << "Initial Bureaucrat:\n" << bureaucrat << std::endl;
        std::cout << "Initial AForm:\n" << AForm << std::endl;

        // Signing the AForm (should throw GradeTooLowException)
        try {
            bureaucrat.signAForm(AForm);
        } catch (const Bureaucrat::GradeTooLowException& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        // Incrementing Bureaucrat's grade
        ++bureaucrat;
        std::cout << "After increment: " << bureaucrat << std::endl;

        // Trying to sign the AForm again (should succeed now)
        bureaucrat.signAForm(AForm);
        std::cout << "After signing: " << AForm << std::endl;

        // Trying to create a AForm with a very high signing grade (should throw GradeTooHighException)
        try {
            AForm highGradeAForm("HighGradeDoc", 200, 100);
        } catch (const AForm::GradeTooHighException& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    } catch (const AForm::GradeTooHighException& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    } catch (const AForm::GradeTooLowException& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "General exception caught: " << e.what() << std::endl;
    }

    return 0;
}
