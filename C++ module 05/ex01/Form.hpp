#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
    private:
        const std::string name;
        bool sign;
        const int gradeToSign;
        const int gradeToExecute;
    public:
        Form();
        Form(const Form &other);
        Form &operator=(const Form &other);
        ~Form();
    
        Form(std::string _name, bool _sign, int _gradeToSign, int _gradeToExecute);
        std::string getName() const;
        bool getSign() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(Bureaucrat &Beru);

        class GradeTooHighException : public std::exception{
            public:
            const char *what() const throw();
        };
        class GradeTooLowException : public std::exception{
            public:
            const char *what() const throw();
        };
};

std::ostream& operator<<(std::ostream &out, const Form &other);