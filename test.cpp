#include <iostream>

class MyClass {
private:
    int a;
public:
    MyClass(int n){
        std::cout << "constractor called" << std::endl;
        this->a = n;
    };
    MyClass(const MyClass &other){
        if (this == &other){
            std::cout << "self asseignment detected" << std::endl;
            return ;
        }
        std::cout << "copy constractor called" << std::endl;
        a = other.a;
    };
    MyClass &operator=(const MyClass &other){
        std::cout << "copy assignment operator called" << std::endl;
        this->a = other.a;
        return(*this);
    };
    ~MyClass(){
        std::cout << "deconstractor called" << std::endl;
    };
    MyClass operator+(const MyClass &other) const{
        std::cout << "oveload operator + called" << std::endl;
        return MyClass(a + other.a);
    }
    void display() const{
        std::cout << "the value is " << a << std::endl;
    }
    bool operator>(const MyClass &other) const{
        std::cout << "oveload operator > called" << std::endl;
        return a > other.a;
    }
    bool operator<(const MyClass &other) const{
        std::cout << "oveload operator < called" << std::endl;
        return a < other.a;
    }

};

int main() {
    MyClass first(5);
    MyClass secound(10);
    MyClass third (first);
    MyClass result(third < secound);

    result.display();
}
