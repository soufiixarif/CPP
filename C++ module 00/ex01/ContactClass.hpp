#pragma once
#include <iostream>

class Contact{

private :
    std::string FirstName;
    std::string LastName;
    std::string NickName;
    std::string DarkestSecret;
    std::string PhoneNumber;
public :
    Contact();
    void SetFirstName(std::string f_Name);
    void SetLastName(std::string l_Name);
    void SetNickName(std::string n_Name);
    void SetDarkestSecret(std::string d_Secret);
    void SetPhoneNumber(std::string Ph_Num);
};
