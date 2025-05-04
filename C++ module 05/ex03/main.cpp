#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

// intern exception
int main(){
    Intern hofar;
    AForm* wati9a;
    Bureaucrat soufiix("soufiix", 1);

    wati9a = hofar.makeForm("shrubbery creation", "soufiix");
    if (wati9a == NULL)
        return 1;
    soufiix.signForm(*wati9a);
    wati9a->execute(soufiix);
}