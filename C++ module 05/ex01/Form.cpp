#include "Form.hpp"

Form::Form(): name("default Form"), gradeToSign(100), gradeToExecute(100){
    this->sign = false;
}

Form &Form::operator=(const Form &other){
    if (this == &other)
        return *this;
    this->sign = other.getSign();
    return *this;
}

Form::Form(const Form &other):name(other.getName()), gradeToSign(other.getGradeToSign()), gradeToExecute(other.getGradeToExecute()){
    *this = other;
}

Form::~Form(){

}

Form::Form(std::string _name, bool _sign, int _gradeToSign, int _gradeToExecute):name(_name), gradeToSign(_gradeToSign), gradeToExecute(_gradeToExecute){
    if (_gradeToExecute > 150 || _gradeToSign > 150)
        throw Form::GradeTooLowException();
    else if (_gradeToExecute < 1 || _gradeToSign < 1)
        throw Form::GradeTooHighException();
    this->sign = _sign;    
}

std::string Form::getName()const{
    return this->name;
}

bool Form::getSign() const{
    return this->sign;
}

int Form::getGradeToExecute() const {
    return this->gradeToExecute;
}

int Form::getGradeToSign() const {
    return this->gradeToSign;
}

void Form::beSigned(Bureaucrat &Beru){
    if (Beru.getGrade() <= this->getGradeToSign())
        this->sign = true;
    else
        throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw(){
    return "Grade too high!";
}

const char *Form::GradeTooLowException::what() const throw(){
    return "Grade too Low!";
}

std::ostream& operator<<(std::ostream &out, const Form &_Form){
    out << "Form " << _Form.getName() << " grade to signe: " << _Form.getGradeToSign() << " grade to execute: " << _Form.getGradeToExecute() << " his status is ";
    out << ((_Form.getSign()) ? "signed" : "not signed") << std::endl;
    return out;
}