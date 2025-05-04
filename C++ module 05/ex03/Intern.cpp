#include "Intern.hpp"

Intern::Intern(){}

Intern &Intern::operator=(const Intern &other){
    (void) other;
    return *this;
}

Intern::Intern(const Intern &other){
    (void) other;
}

Intern::~Intern(){}

AForm *Intern::creatShrubberyCreationForm(std::string target){
    return new ShrubberyCreationForm(target);
}
AForm *Intern::creatRobotomyRequestForm(std::string target){
    return new RobotomyRequestForm(target);
}
AForm *Intern::creatPresidentialPardonForm(std::string target){
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string target){
    int i;
    std::string arr[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    ptrToMem ptr[] = {&Intern::creatShrubberyCreationForm, &Intern::creatRobotomyRequestForm, &Intern::creatPresidentialPardonForm};
    for (i = 0; (formName != arr[i] && i < 3); i++);
    if (i == 3){
        std::cout << "laaaaa" << std::endl;
        return (NULL);
    }
    return (this->*ptr[i])(target);
}