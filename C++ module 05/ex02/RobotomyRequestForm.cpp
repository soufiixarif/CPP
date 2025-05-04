#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():AForm("RobotomyRequestForm", false, 72, 45), _target("RobotomyRequestForm"){

}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other){
    if (this == &other)
        return *this;
    this->_target = other._target;
    return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other):AForm("RobotomyRequestForm", false, 72, 45){
    if (this == &other)
        return;
    *this = other;
}

RobotomyRequestForm::~RobotomyRequestForm(){

}

RobotomyRequestForm::RobotomyRequestForm(std::string &_target):AForm(_target, false, 72, 45), _target(_target){
    
}

void RobotomyRequestForm::execute(Bureaucrat const & execute) const{
    if (this->getSign() == false)
        throw AForm::formNotSigned();
    else if (execute.getGrade() > 45)
        throw Bureaucrat::GradeTooLowException();
    std::cout << "drilling noises............!!" << std::endl;
    srand(time(0));
    if (rand() % 2 == 0)
        std::cout << this->_target << " has been robotomized successfully" << std::endl;
    else
        std::cout << " the robotomy failed" << std::endl;
}