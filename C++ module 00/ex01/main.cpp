#include "PhoneBookClass.hpp"
#include "ContactClass.hpp"


using std::string;

int full_of_space(string in)
{
    for (int i = 0; in[i]; i++)
        if (in[i] != ' ')
            return(0);
    return (1);
}

string  prompt(string str)
{
    string in;
    while (1)
    {
        std::cout << str << std::endl;
        std::getline(std::cin, in);

        if (std::cin.eof())
            exit(0);

        if(!in.empty() && !full_of_space(in))
            return in;
    }
}


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
        if (i == 8)
            i = 0;
        std::cout << "enter your commande" << std::endl;
        std::getline(std::cin, input);
        if (std::cin.eof())
            exit(0);
        if (input != "ADD" && input != "SEARCH" && input != "EXIT")
            std::cout << "please enter a valid commande: ADD or SEARCH or EXIT" << std::endl;
        else if (input == "ADD")// check for empty and full of spaces
        {
            contact.SetFirstName(prompt("---- Enter First Name -----"));
            contact.SetLastName(prompt("---- Enter Last Name -----"));
            contact.SetNickName(prompt("---- Enter Nick Name -----"));
            contact.SetDarkestSecret(prompt("-- Enter Darkest secret --"));
            contact.SetPhoneNumber(prompt("--- Enter Phone Number ---"));
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