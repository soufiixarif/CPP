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

    try {
        wati9a = hofar.makeForm("presidential pardon", "soufiix");
    }catch (const Intern::formNotFound &e){
        std::cerr << e.what() << std::endl;
    }
    soufiix.signForm(*wati9a);
    wati9a->execute(soufiix);
}