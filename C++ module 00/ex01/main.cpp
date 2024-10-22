#include "PhoneBookClass.hpp"
#include "ContactClass.hpp"

int main()
{
    PhoneBook phonebook;
    Contact   contact;
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string darkestSecret;
    std::string phoneNumber;
    std::string input;
    int i = 0;

    std::cout << "=====> Soufiix Phone <=====" << std::endl;
    while (1){
        if (i == 7)
            i = 0;
        std::cout << "enter your commande" << std::endl;
        std::getline(std::cin, input);
        if (input != "ADD" && input != "SEARCH" && input != "EXIT")
        {
            std::cout << ">" << input << "<" << std::endl;
            std::cout << "please enter a valid commande" << std::endl;
        }
        else if (input == "ADD")// check for empty and full of spaces
        {
            std::cout << "---- Enter First Name -----" << std::endl;
            std::getline(std::cin, firstName);
            contact.SetFirstName(firstName);
            std::cout << "---- Enter Last Name -----" << std::endl;
            std::getline(std::cin, lastName);
            contact.SetLastName(lastName);
            std::cout << "---- Enter Nick Name -----" << std::endl;
            std::getline(std::cin, nickName);
            contact.SetNickName(nickName);
            std::cout << "-- Enter Darkest secret --" << std::endl;
            std::getline(std::cin, darkestSecret);
            contact.SetDarkestSecret(darkestSecret);
            std::cout << "--- Enter Phone Number ---" << std::endl;
            std::getline(std::cin, phoneNumber);
            contact.SetPhoneNumber(phoneNumber);
            phonebook.AddContact(contact, i);
            i++;
        }
        else if (input == "SEARCH"){
            phonebook.SearchContact();
        }
        else if (input == "EXIT")
            exit(0);
    }
}