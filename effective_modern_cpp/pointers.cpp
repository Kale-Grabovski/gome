#include <iostream>

int main () {
    int x = 7;
    int y = 8;

    // Case #1 - constant shit the pointer points to
    const int* p1 = &x;
    p1 = &y; // ok
    //*p1 = 4; // error
    std::cout << *p1 << std::endl;

    // Case #2 (same as Case #1)
    int const * p2 = &x;
    p2 = &y; // ok
    //*p2 = 4; // error
    std::cout << *p2 << std::endl;

    // Case #3 - constant pointer itself
    int * const p3 = &x;
    //p3 = &y; // error 
    std::cout << *p3 << std::endl;

    // Case #4 - constant pointer and constant shit the pointer points to
    const int * const p4 = &x;
    //p4 = &y; // error 
    //*p4 = 4; // error
    std::cout << *p4 << std::endl;
}
