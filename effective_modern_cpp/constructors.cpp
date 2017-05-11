#include <iostream>

class A 
{
    public:
    A() {
        std::cout << "Default ctor" << std::endl;
    }

    A(int a) {
        std::cout << "Redefined with int " << a << std::endl;
    }

    A(const A& rhs) {
        std::cout << "Copy ctor" << std::endl;
    }

    A& operator= (const A& rhs) {
        std::cout << "Assign operator" << std::endl;
    }
};

int main() {
    A orig(5);   // Redefined
    A a1 = orig; // Copy ctor
    A a2(orig);  // Copy ctor
    A a3;        // Default ctor
    a3 = orig;   // Assign operator

    return 0;
}
