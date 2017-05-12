#include <iostream>

class Point {
    public:
    // C++14
    constexpr Point (double xVal, double yVal) noexcept : x(xVal), y(yVal) {}
    constexpr double xValue() const { return x; }
    constexpr double yValue() const { return y; }

    void setX(double newX) noexcept { x = newX; }
    void setY(double newY) noexcept { y = newY; }

    private:
    double x, y;
};

int main() {
    constexpr Point p1(1.1, 2.2); // Calcs at compile time

    std::cout << p1.xValue() << std::endl;
    return 0;
}
