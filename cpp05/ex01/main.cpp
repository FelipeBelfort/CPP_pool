#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
        // Creating a Bureaucrat and a Form
        Bureaucrat bureaucrat("John", 41);
        Form form("Document", 40, 30);

        // Displaying initial information
        std::cout << "Initial Bureaucrat:\n" << bureaucrat << std::endl;
        std::cout << "Initial Form:\n" << form << std::endl;

        // Signing the form (should throw GradeTooLowException)
            bureaucrat.signForm(form);

        // Incrementing Bureaucrat's grade
        ++bureaucrat;
        std::cout << "After increment: " << bureaucrat << std::endl;

        // Trying to sign the form again (should succeed now)
        bureaucrat.signForm(form);
        std::cout << "After signing: " << form << std::endl;

        // Trying to create a Form with a very high signing grade (should throw GradeTooHighException)
        try {
            Form highGradeForm("HighGradeDoc", 0, 100);
        }
        catch (const std::exception &e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
        // Trying to create a Form with a very high signing grade (should throw GradeTooHighException)
        try {
            Form lowGradeForm("LowGradeDoc", 200, 100);
        }
        catch (const std::exception &e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

    return 0;
}
