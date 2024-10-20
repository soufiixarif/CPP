#include "PhoneBookClass.hpp"
#include "ContactClass.hpp"

Contact::Contact()
{

}

PhoneBook::PhoneBook()
{

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
void PhoneBook::AddContact(Contact c, size_t index){
    this->contact[index] = c;
}
// void PhoneBook::SearchContact(size_t index)
// {
//     if (index < 0 || index > 7 || index > this->last_idx - 1)
//     {
//         // display an error message;
//         return ;
//     }
//     return ;
// }
void PhoneBook::Exit(void){
    exit(0);
}

//
std::string Contact::GetFirstName(){
    return(FirstName);
}