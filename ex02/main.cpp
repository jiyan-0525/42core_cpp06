#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base* generate() {
    int randomValue = std::rand() % 3;
    switch (randomValue) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return nullptr;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*> (p)) 
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*> (p)) 
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*> (p)) 
        std::cout << "C" << std::endl;
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&> (p);
        std::cout << "A" << std::endl;
        (void)a;
        return;
    } catch (const std::exception& e) {
    }
    try {
        B& b = dynamic_cast<B&> (p);
        std::cout << "B" << std::endl;
        (void)b;
        return;
    } catch (const std::exception& e) {}
    try {
        C& c = dynamic_cast<C&> (p);
        std::cout << "C" << std::endl;
        (void)c;
        return;
    } catch (const std::exception& e) {}
}

int main() {
    std::srand(std::time(0));
    
    for (int i = 0; i < 4; i++) {
        Base* obj = generate();
        
        std::cout << "Identify via pointer: ";
        identify(obj);
        
        std::cout << "Identify via reference: ";
        identify(*obj);
        
        delete obj;
        std::cout << std::endl;
    }

    return 0;
}
