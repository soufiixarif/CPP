#include <iostream>

class Contact {
private:
    std::string FirstName;
    std::string LastName;
    std::string PhoneNumber;

public:
    // Default Constructor
    Contact() : FirstName(""), LastName(""), PhoneNumber("") {}

    // Parameterized Constructor
    Contact(std::string f_name, std::string l_name, std::string phone_num) {
        FirstName = f_name; 
        LastName = l_name; 
        PhoneNumber = phone_num;
    }

    void display() const {
        std::cout << "Name: " << FirstName << " " << LastName << std::endl;
        std::cout << "Phone: " << PhoneNumber << std::endl;
    }
};

class PhoneBook {
private:
    Contact contact[8];
    size_t last_idx;

public:
    // Constructor initializes `last_idx` to 0
    PhoneBook() : last_idx(0) {}

    // Method to add a contact (simplified example)
    void addContact(const Contact& newContact) {
        if (last_idx < 8) {
            contact[last_idx] = newContact;
            last_idx++;
        } else {
            std::cout << "PhoneBook is full!" << std::endl;
        }
    }

    void displayAllContacts() const {
        for (size_t i = 0; i < last_idx; ++i) {
            contact[i].display();
            std::cout << "-----------------" << std::endl;
        }
    }
};

int main() {
    PhoneBook phoneBook;
    Contact john("John", "Doe", "123-456-7890");
    Contact soufiix("soufiix", "Doe", "123-456-7890");
    Contact roufiix("roufiix", "Doe", "123-456-7890");
    Contact lmlih("lmlih", "Doe", "123-456-7890");
    Contact nadi("nadi", "Doe", "123-456-7890");
    Contact jane("Jane", "Doe", "987-654-3210");
    Contact lpit("lpit", "Doe", "987-654-3210");
    Contact lkit("lkit", "Doe", "987-654-3210");
    Contact sit("sit", "Doe", "987-654-3210");

    phoneBook.addContact(john);
    phoneBook.addContact(jane);
    phoneBook.addContact(soufiix);
    phoneBook.addContact(roufiix);
    phoneBook.addContact(lmlih);
    phoneBook.addContact(nadi);
    phoneBook.addContact(lpit);
    phoneBook.addContact(lkit);
    phoneBook.addContact(sit);

    phoneBook.displayAllContacts();

    return 0;
}