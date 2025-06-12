#include "Base.hpp"
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void){
    srand(time(0));
    int random = std::rand() % 3;
    if (random == 1){
        std::cout << "Generat A object" << std::endl;
        return new A();
    }
    else if (random == 2){
        
        std::cout << "Generat B object" << std::endl;
        return new B();
    }
    else{
        
        std::cout << "Generat C object" << std::endl;
        return new C();
    }
}

void identify(Base* p){
    A* aptr = dynamic_cast<A*>(p);
    if (aptr != NULL)
        std::cout << "A" << std::endl;

    B* bptr = dynamic_cast<B*>(p);
    if (bptr != NULL)
        std::cout << "B" << std::endl;

    C* cptr = dynamic_cast<C*>(p);
    if (cptr != NULL)
        std::cout << "C" << std::endl;
}

void identify(Base& p){
    try{
        A& aptr = dynamic_cast<A&>(p);
        (void)aptr;
        std::cout << "A" << std::endl;
    }catch(...){}
    try{
        B& bptr = dynamic_cast<B&>(p);
        (void)bptr;
        std::cout << "B" << std::endl;   
    }catch(...){}
    try{
        C& cptr = dynamic_cast<C&>(p);
        (void)cptr;
        std::cout << "C" << std::endl;
    }catch(...){}
}

int main(){
    Base *AA = generate();

    std::cout << "---------------------identify by pointer--------------------" << std::endl;

    identify(AA);
    
    std::cout << "----------------------identify by reference-----------------" << std::endl;
    
    identify(*AA);

    delete AA;
}
