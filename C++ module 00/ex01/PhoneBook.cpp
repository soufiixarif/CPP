#include "PhoneBookClass.hpp"
#include "ContactClass.hpp"

Contact::Contact(){

}

PhoneBook::PhoneBook()
{
    this->size = 0;
}

std::string to_dispay(std::string line)
{
    std::string res;

    if (line.size() > 10){
        res = line;
        res[9] = '.';
        res[10] = '\0';
        res.resize(10);
        return (res);
    }
    else{
        while (line.size() < 10)
            line = ' ' + line;
    }
    return (line);
}
void Contact::SetFirstName(std::string f_Name){
    this->FirstName = f_Name;
}
void Contact::SetLastName(std::string l_name){
    this->LastName = l_name;
}
void Contact::SetNickName(std::string n_name){
    this->NickName = n_name;
}
void Contact::SetDarkestSecret(std::string d_Secret){
    this->DarkestSecret = d_Secret;
}
void Contact::SetPhoneNumber(std::string Ph_Num){
    this->PhoneNumber = Ph_Num;
}
std::string Contact::
GetFirstName(){
    return(FirstName);
}
std::string Contact::GetLastName(){
    return(LastName);
}
std::string Contact::GetNickName(){
    return(NickName);
}
std::string Contact::GetDarkestSecret(){
    return(DarkestSecret);
}
std::string Contact::GetPhoneNumber(){
    return(PhoneNumber);
}
void PhoneBook::AddContact(Contact c, size_t index){
    this->contact[index] = c;
    if(this->size < 8)
        this->size++;
}
#include <sstream>

int ft_itoa(std::string str) {
    std::stringstream ss(str);

    int num;
    ss >> num;
    if (ss.fail() || num > 7 || num < 0){
        std::cout << "inter a valid number" << std::endl;
        return(-1);
    }
    return num;
}

void PhoneBook::SearchContact(){
    std::string input;
    int index;

    std::cout << "_____________________________________________" << std::endl;
    std::cout << "|" << "     index" << "|" << "first name" << "|" << " last name" << "|" << "  nickname" << "|" << std::endl;
    std::cout << "|__________|__________|__________|__________|" << std::endl;
    for(size_t i = 0; i < size; i++){
        std::cout << "|" << to_dispay(std::to_string(i)) << "|" << to_dispay(contact[i].GetFirstName()) << "|" << to_dispay(contact[i].GetLastName()) << "|" << to_dispay(contact[i].GetNickName()) << "|" << std::endl;
    }
    std::cout << "|__________|__________|__________|__________|" << std::endl;
    if (size == 0)
        std::cout << "contact list empty" << std::endl;
    else{
        std::cout << "enter the index of contact you want to display" << std::endl;
        std::getline(std::cin, input);
        if (std::cin.eof())
            exit(0);
        index = ft_itoa(input);
        if(index == -1)
            return;
        else{
            std::cout << "Contact Details:" << std::endl;
            std::cout << "First Name: " << contact[index].GetFirstName() << std::endl;
            std::cout << "Last Name: " << contact[index].GetLastName() << std::endl;
            std::cout << "Nick Name: " << contact[index].GetNickName() << std::endl;
            std::cout << "Darkest Secret: " << contact[index].GetDarkestSecret() << std::endl;
            std::cout << "Phone Number: " << contact[index].GetPhoneNumber() << std::endl;
        }
    }
    return ;
}
void PhoneBook::Exit(void){
    exit(0);
}
