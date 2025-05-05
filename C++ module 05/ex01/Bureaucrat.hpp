#pragma once
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();
        
        Bureaucrat(std::string _Name, int _grade);
        std::string getName() const;
        int getGrade() const;

        void increment();
        void decrement();

        void signForm(Form &Form);

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &other);