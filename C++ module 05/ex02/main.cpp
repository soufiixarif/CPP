#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(){
    std::string target = "lwati9a lmliha";
    Bureaucrat soufiix("soufiix", 6);

    PresidentialPardonForm wati9a1(target);

    soufiix.signForm(wati9a1);
    soufiix.increment();
    try{
        soufiix.executeForm(wati9a1);
    }catch (const AForm::formNotSigned &e){
        std::cerr << e.what() << std::endl;
    }catch (const Bureaucrat::GradeTooLowException &e){
        std::cerr << e.what() << std::endl;
    }

    std::cout << wati9a1 << std::endl;
}