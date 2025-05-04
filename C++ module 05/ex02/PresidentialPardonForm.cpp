#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("PresidentialPardonForm",false,25, 5){}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other){
    if (this == &other)
        return *this;
    this->_target = other._target;
    return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other):AForm("PresidentialPardonForm",false,25, 5){
    if (this == &other)
        return ;
    *this = other;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(std::string &target):AForm("PresidentialPardonForm",false,25, 5){
    this->_target = target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if (this->getSign() == false)
        throw AForm::formNotSigned();
    else if (executor.getGrade() > 5)
        throw Bureaucrat::GradeTooLowException();
    else
        std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

