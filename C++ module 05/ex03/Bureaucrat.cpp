#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("default"){
    this->grade = 100;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other){
    if (this == &other)
        return *this;
    this->grade = other.getGrade();
    return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other){
    *this = other;
}

Bureaucrat::~Bureaucrat(){

}

Bureaucrat::Bureaucrat(std::string _Name, int _grade):name(_Name){
    if (_grade > 150)
        throw GradeTooLowException();
    else if (_grade < 1)
        throw GradeTooHighException();
    else
        this->grade = _grade;
}

std::string Bureaucrat::getName() const{
    return this->name;
}

int Bureaucrat::getGrade() const{
    return this->grade;
}

void Bureaucrat::increment(){
    if (this->grade - 1 < 1)
        throw GradeTooHighException();
    else
        this->grade -= 1;
}

void Bureaucrat::decrement(){
    if (this->grade + 1 > 150)
        throw GradeTooLowException();
    else
        this->grade += 1;
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
    return "Grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
    return "Grade too low!";
}

void Bureaucrat::signForm(AForm &_AForm){
    try{
        _AForm.beSigned(*this);
        std::cout << this->getName() << " signed " << _AForm.getName() << std::endl;
    }catch (const AForm::GradeTooLowException &e){
        std::cout << this->getName() << " couldn't signe " << _AForm.getName() << " becaus " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form){
    if (form.getSign() == false)
        throw AForm::formNotSigned();
    else if (this->getGrade() > form.getGradeToExecute())
        throw Bureaucrat::GradeTooLowException();
    try{
        form.execute(*this);
    }catch(Bureaucrat::GradeTooLowException &e){
        std::cerr << e.what() << std::endl;
    }
    std::cout << this->getName() << " execute " << form.getName() << std::endl;
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &other)
{
    out << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
    return out;
}