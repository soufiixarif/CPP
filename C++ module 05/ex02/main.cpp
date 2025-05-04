#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(){
    Bureaucrat soufiix("soufiix", 6);
    std::string target = "kaghit";
    // RobotomyRequestForm robo(target);
    PresidentialPardonForm haha(target);

    soufiix.signForm(haha);
    try{
        soufiix.executeForm(haha);
    } catch (const Bureaucrat::GradeTooLowException &e){
        std::cerr << e.what() << std::endl;
    }
    // // ShrubberyCreationForm kaghit(target);
    // soufiix.signForm(haha);
    // // std::cout << "tale3 nivo chwia" << std::endl;
    // soufiix.increment();
    // try {
    //     haha.execute(soufiix);
    // }catch (const Bureaucrat::GradeTooHighException &e){
    //     std::cerr << e.what() << std::endl;
    // }catch (const Bureaucrat::GradeTooLowException &e){
    //     std::cerr << e.what() << std::endl;
    // }
    // std::cout << "sini hna" << std::endl;
    // soufiix.signForm(kaghit);
    // try{
    //     kaghit.execute(soufiix);
    // }catch (const AForm::formNotSigned &e){
    //     std::cerr << e.what() << std::endl;
    // }catch (const Bureaucrat::GradeTooLowException &e){
    //     std::cerr << e.what() << std::endl;
    // }
}