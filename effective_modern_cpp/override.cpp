#include <memory>
#include <iostream>
#include <vector>

class Base {
    public:
    virtual void func() {
        std::cout << "Base" << std::endl;
    }
};

class Derived : public Base {
    public:
    // With even little differences between base and derived method compiler will fuck you up,
    // but only in a case you didn't forget to add "override" keyword. Bye.
    virtual void func() override {
        std::cout << "Derived" << std::endl;
    }
};

class Widget {
    public:
    using DataType = std::vector<double>;

    Widget(DataType d) : values(d) {}
    Widget() : values(DataType{1.1, 2.2}) {}

    // For lvalue Widget returns lvalue, dont forget second &
    DataType& data() & { 
        return values; 
    }   

    // For rvalue Widget returns rvalue, dont forget second &&
    DataType&& data() && { 
        return std::move(values); 
    }

    DataType values;
};

// Fabric method
Widget makeWidget() {
    Widget w(std::vector<double>{3.3, 4.4});
    return w;
}

int main() {
    std::shared_ptr<Base> d = std::make_shared<Derived>();
    d->func(); // OK - overriden method is fired

    Widget w;

    auto z = w.data(); // lvalue
    std::cout << z[0] << std::endl;

    auto z2 = makeWidget().data(); // rvalue made by move
    std::cout << z2[1] << std::endl;

    return 0;
}
