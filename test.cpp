#include <iostream>

class MyClass {
public:
    void myFunction(int x) {
        std::cout << "Value: " << x << std::endl;
    }
};

int main() {
    MyClass obj;
    void (MyClass::*funcPtr)(int) = &MyClass::myFunction;  // Declare and assign
    
    // Call via object
    (obj.*funcPtr)(42);

    // Call via pointer to object
    MyClass* objPtr = &obj;
    (objPtr->*funcPtr)(42);

    return 0;
}
