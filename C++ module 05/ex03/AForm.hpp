#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
    private:
        const std::string name;
        bool sign;
        const int gradeToSign;
        const int gradeToExecute;
    public:
        AForm();
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        virtual ~AForm();
    
        AForm(std::string _name, bool _sign, int _gradeToSign, int _gradeToExecute);
        std::string getName() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        bool getSign() const;

        void beSigned(Bureaucrat &Beru);

        virtual void execute(Bureaucrat const & executor) const = 0;
        class GradeTooHighException : public std::exception{
            public:
            const char *what() const throw();
        };
        class GradeTooLowException : public std::exception{
            public:
            const char *what() const throw();
        };
        class formNotSigned : public std::exception{
            public :
            const char *what() const throw();
        };
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &other);