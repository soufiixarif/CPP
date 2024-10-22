#pragma once

#include <iostream>
#include "ContactClass.hpp"

class PhoneBook{
private :
    Contact contact[8];
    size_t  size;
public :
    PhoneBook();
    void    AddContact(Contact c, size_t index);
    void    SearchContact();
    void    Exit(void);
};
