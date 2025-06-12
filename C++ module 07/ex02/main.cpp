#include <iostream>
#include "Array.hpp"

int main() {
    try {
        std::cout << "== Template Test with std::string ==" << std::endl;
        Array<std::string> strArray(3);
        strArray[0] = "hello";
        strArray[1] = "Soufiix";
        strArray[2] = ":-D";
        for (unsigned int i = 0; i < strArray.size(); ++i) {
            std::cout << "strArray[" << i << "] = " << strArray[i] << std::endl;
        }
        std::cout << "\n== Out-of-Bounds Access: strArray ==" << std::endl;
        std::cout << strArray[50] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "[EXCEPTION] " << e.what() << std::endl;
    }

    try {
        std::cout << "\n== Template Test with int==" << std::endl;
        std::cout << "== Default Construction ==" << std::endl;
        Array<int> a;
        std::cout << "Size: " << a.size() << std::endl;

        std::cout << "\n== Construction with size ==" << std::endl;
        Array<int> b(5);
        std::cout << "Size: " << b.size() << std::endl;
        for (unsigned int i = 0; i < b.size(); ++i) {
            std::cout << "b[" << i << "] = " << b[i] << std::endl;
        }

        std::cout << "\n== Modifying elements ==" << std::endl;
        for (unsigned int i = 0; i < b.size(); ++i) {
            b[i] = i * 10;
        }
        for (unsigned int i = 0; i < b.size(); ++i) {
            std::cout << "b[" << i << "] = " << b[i] << std::endl;
        }

        std::cout << "\n== Copy Constructor ==" << std::endl;
        Array<int> c(b);
        for (unsigned int i = 0; i < c.size(); ++i) {
            std::cout << "c[" << i << "] = " << c[i] << std::endl;
        }

        std::cout << "\n== Modify copy and check original ==" << std::endl;
        c[0] = 999;
        std::cout << "c[0] = " << c[0] << " (modified)" << std::endl;
        std::cout << "b[0] = " << b[0] << " (should be unchanged)" << std::endl;

        std::cout << "\n== Assignment Operator ==" << std::endl;
        Array<int> d;
        d = b;
        for (unsigned int i = 0; i < d.size(); ++i) {
            std::cout << "d[" << i << "] = " << d[i] << std::endl;
        }

        std::cout << "\n== check with const ==" << std::endl;
        const Array<int> z(c);
        for (unsigned int i = 0; i < z.size(); ++i) {
            std::cout << "z[" << i << "] = " << z[i] << std::endl;
        }


        std::cout << "\n== Out-of-Bounds Access: Array ==" << std::endl;
        std::cout << d[50] << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "[EXCEPTION] " << e.what() << std::endl;
    }
    return 0;
}