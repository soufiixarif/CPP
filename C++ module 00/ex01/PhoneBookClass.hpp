#pragma once

#include <iostream>
#include "ContactClass.hpp"

class PhoneBook{
private :
    Contact contact[8];
    // size_t  last_idx;
public :
    PhoneBook();
    void    AddContact(Contact c, size_t index);
    // void    SearchContact(size_t index);
    void    Exit(void);
};
