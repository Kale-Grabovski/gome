#include <iostream>

template<typename T>
void processPointer(T* ptr) {
    std::cout << *ptr << std::endl;
}

template<>
void processPointer<void>(void*) = delete;

template<>
void processPointer<char>(char*) = delete;

int main() {
    float z = 100;
    float* p1 = &z;
    processPointer(p1); // OK

    char* c = (char*)"Wrong";
    //processPointer(c); // Doesn't compile

    return 0;
}
