#pragma once
#include "iostream"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern{

    public:
        Intern();
        Intern &operator=(const Intern &other);
        Intern(const Intern &other);
        ~Intern();

        AForm *creatShrubberyCreationForm(std::string target);
        AForm *creatRobotomyRequestForm(std::string target);
        AForm *creatPresidentialPardonForm(std::string target);
        AForm* makeForm(std::string formName, std::string target);
        typedef AForm* (Intern::*ptrToMem)(std::string);
};