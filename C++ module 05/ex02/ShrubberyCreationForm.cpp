#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm():AForm("ShrubberyCreationForm", false, 145, 137), target("default"){

}
ShrubberyCreationForm::ShrubberyCreationForm(std::string &_target): AForm(_target, false, 145, 137), target(_target){
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other){
    if (this == &other)
        return *this;
    this->target = other.target;
    return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):AForm(other.getName(), other.getSign(), other.getGradeToSign(), other.getGradeToExecute()){
    *this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){

}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const{
    if (this->getSign() == false)
        throw AForm::formNotSigned();
    else if (executor.getGrade() > 137)
        throw Bureaucrat::GradeTooLowException();
    std::string Fname = this->target + "_shrubbery";
    std::ofstream outputfile(Fname);
    if (outputfile.is_open()){
        outputfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣤⣦⣤⣤⣄⣀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
        outputfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⠟⡍⢆⡱⠌⢥⠋⡝⣩⢋⠛⡿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
        outputfile << "⠀⠀⠀⠀⠀⠀⠀⢀⣤⣴⣶⠾⢏⡜⠰⡡⢆⠹⡠⢋⠔⡢⢌⠓⡤⢛⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
        outputfile << "⠀⠀⠀⠀⠀⢀⣾⠟⣩⠒⢤⡉⠦⢌⠣⡑⠬⣑⠢⢍⡒⠥⢊⡑⢆⠣⢿⡷⢶⣤⡀⠀⠀⠀⠀⠀⠀\n";
        outputfile << "⠀⠀⠀⠀⠀⢸⡟⡘⢤⡉⠦⣘⠡⢎⡡⢍⠲⢄⡋⠴⡘⠬⡑⡌⢎⠒⡅⢎⢢⡙⣷⡀⠀⠀⠀⠀⠀\n";
        outputfile << "⠀⠀⠀⠀⣠⣼⡿⠘⣄⠸⢃⡄⡛⠤⣀⠇⠼⢠⡘⢣⡘⢣⠸⢠⠜⢣⠸⢄⣃⠸⣻⣇⠀⠀⠀⠀⠀\n";
        outputfile << "⠀⢀⣴⡿⢋⡕⢢⡙⠤⣉⠖⡰⢉⡒⡡⢎⢡⢃⠬⡡⠜⡡⢎⠡⢎⡡⠚⢤⢂⡓⣘⠛⠿⣶⣄⠀⠀\n";
        outputfile << "⠀⣾⢏⡰⢃⠜⡰⢌⡒⡡⠎⡔⠣⣌⠱⢌⢢⡉⠦⣑⢡⠣⢌⡃⠦⣑⠩⡒⠬⡰⢡⡉⢖⡰⢹⣷⠀\n";
        outputfile << "⠸⣿⢂⠦⣉⠲⠡⢆⡑⢆⠓⠬⡑⠤⠓⡌⢆⠜⡡⢆⠣⠜⢢⠜⡡⢆⠣⢅⡓⡰⢡⢊⡒⢌⠆⣿⡇\n";
        outputfile << "⠀⠻⣧⡒⡡⢎⡑⢎⠰⡊⢍⡒⢩⠜⣵⡘⠬⡘⡔⢊⡌⢣⣃⡜⢰⢊⠱⡌⠴⣁⠣⢆⡉⠖⣸⡿⠀\n";
        outputfile << "⠀⢰⡿⢡⡑⠦⡘⡌⡱⢘⢢⢉⠖⣸⣿⣿⣦⡱⠌⣥⣼⣾⣿⢃⠣⡌⢣⢘⠒⡌⡱⢂⣭⣾⠟⠁⠀\n";
        outputfile << "⠀⢸⣷⠡⠜⢢⠱⣌⡑⠎⡤⢃⢮⣿⣿⣿⣿⡟⡿⣿⣿⣿⣿⡌⡱⢌⣑⣊⠱⣘⠰⢃⣿⡇⠀⠀⠀\n";
        outputfile << "⠀⠀⠻⣷⣭⣆⣣⠛⠿⣿⣶⠿⣿⣟⢿⣿⣿⡟⡜⣿⣿⣿⡿⠿⣿⡿⡛⣃⢣⣼⣦⣷⠟⠁⠀⠀⠀\n";
        outputfile << "⠀⠀⠀⠀⠉⠉⠻⢿⣴⣢⣄⣯⣾⢿⣮⡽⢿⡟⡸⢿⣟⢫⣜⣷⡿⣷⡇⣦⣿⠋⠁⠀⠀⠀⠀⠀⠀\n";
        outputfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠉⠉⠀⠀⠙⣿⣆⠳⣩⠖⣸⣶⡿⠛⠛⠿⠛⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀\n";
        outputfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢼⣧⠛⣤⠛⣼⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
        outputfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡗⡏⣆⢏⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
        outputfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡿⡱⢜⣊⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
        outputfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣟⡥⠳⣌⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
        outputfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣯⠖⡹⢤⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
        outputfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡷⣋⠵⣃⢾⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
        outputfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣯⡕⣮⢱⣾⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
        outputfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣯⡕⢬⣃⢿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
        outputfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣗⠮⡱⣌⠾⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
        outputfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣤⣾⣏⣶⡱⡜⡸⢽⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  \n";
        outputfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣿⣏⣿⡿⠛⣷⣭⣽⣷⣾⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ \n";
        outputfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠁⠀⠀⠈⠛⠛⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    }else{
        std::cout << "file can't open" << std::endl;
    }
    outputfile.close();
}
