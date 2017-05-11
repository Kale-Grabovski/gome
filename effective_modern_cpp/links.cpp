#include <iostream>

template<typename T>
void f(T&& param) {}

double getEpsilon(const double& z) {
    return z / 666;
}

int main () {
    int x = 7;
    const int cx = x;
    const int& rx = x;

    f(x);
    f(cx);
    f(rx);

    double dd = getEpsilon(1000);
    auto ff = static_cast<float>(getEpsilon(1000));
    std::cout << dd << " " << ff << std::endl;
}
