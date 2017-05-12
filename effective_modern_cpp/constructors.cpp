#include <iostream>

class A 
{
    public:
    A() {
        std::cout << "Default ctor" << std::endl;
    }

    // If we define non-default ctor the compiler will not create default ctor,
    // but if we define it as template ctor it will.
    A(int a) {
        std::cout << "Redefined with int " << a << std::endl;
    }

    // = default might be added but only if we have declaration here and implementation in another place
    // Default copy ctor will be removed by compiler if we define move ctor and vise versa.
    A(const A& rhs) { 
        std::cout << "Copy ctor" << std::endl;
    }

    // Assign copy ctor will be removed by compiler if we define move assign ctor and vise versa.
    A& operator= (const A& rhs) {
        std::cout << "Copy assign operator" << std::endl;
    }

    // If we don't define move ctor or move assign operator the compiler will use copy ctor and copy assign.
    // In that case using = default is preferable.
    A(const A&& rhs) { 
        std::cout << "Move ctor" << std::endl;
    }

    A& operator= (const A&& rhs) {
        std::cout << "Move assign operator" << std::endl;
    }

    virtual ~A() {}
};

int main() {
    A orig(5);   // Redefined
    A a1 = orig; // Copy ctor
    A a2(orig);  // Copy ctor
    A a3;        // Default ctor
    a3 = orig;   // Assign operator

    return 0;
}
