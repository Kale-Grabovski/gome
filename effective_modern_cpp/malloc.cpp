#include <iostream>

struct A {
    int a;
    A() {
        std::cout << "Faka";
    }
};

int main() {
    A* ptr1 = (A*)malloc(sizeof(A) * 100); // Just allocates memory to fit 100 of A
    A* ptr2 = new A[100]; // Run default ctor 100 times

    std::cout << std::endl;

    return 0;
}
