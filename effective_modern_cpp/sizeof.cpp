#include <iostream>

struct A {
    char a;
};

struct B {
    int b;
};

struct C {
    char a;
    int b;
};

int main() {
    std::cout << sizeof(A) << std::endl; // 1
    std::cout << sizeof(B) << std::endl; // 4
    std::cout << sizeof(C) << std::endl; // 8 because of types alignment

    return 0;
}
