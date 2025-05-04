#include "AForm.hpp"

AForm::AForm(): name("default AForm"), gradeToSign(100), gradeToExecute(100){
    this->sign = false;
}

AForm &AForm::operator=(const AForm &other){
    if (this == &other)
        return *this;
    this->sign = other.getSign();
    return *this;
}

AForm::AForm(const AForm &other):name(other.getName()), gradeToSign(other.getGradeToSign()), gradeToExecute(other.getGradeToExecute()){
    *this = other;
}

AForm::~AForm(){

}

AForm::AForm(std::string _name, bool _sign, int _gradeToSign, int _gradeToExecute):name(_name), gradeToSign(_gradeToSign), gradeToExecute(_gradeToExecute){
    if (_gradeToExecute > 150 || _gradeToSign > 150)
        throw AForm::GradeTooLowException();
    else if (_gradeToExecute < 1 || _gradeToSign < 1)
        throw AForm::GradeTooHighException();
    else
        this->sign = _sign;    
}

std::string AForm::getName()const{
    return this->name;
}

bool AForm::getSign() const{
    return this->sign;
}

int AForm::getGradeToExecute() const {
    return this->gradeToExecute;
}

int AForm::getGradeToSign() const {
    return this->gradeToSign;
}

void AForm::beSigned(Bureaucrat &Beru){
    if (Beru.getGrade() <= this->getGradeToSign())
        this->sign = true;
    else
        throw AForm::GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw(){
    return "Grade too high!";
}

const char *AForm::GradeTooLowException::what() const throw(){
    return "Grade too Low!";
}

const char *AForm::formNotSigned::what() const throw(){
    return "form not signed!";
}

std::ostream& operator<<(std::ostream &out, const AForm &_AForm){
    out << "AForm " << _AForm.getName() << " grade to signe: " << _AForm.getGradeToSign() << " grade to execute: " << _AForm.getGradeToExecute() << " his status is ";
    out << ((_AForm.getSign()) ? "signed" : "not signed") << std::endl;
    return out;
}