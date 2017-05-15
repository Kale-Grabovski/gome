#include <memory>
#include <iostream>
#include <vector>

class Widget {};

void processWidget(std::shared_ptr<Widget> w) {
    // Do something
}

int main() {
    auto shared = std::make_shared<Widget>(); // ref counter = 1
    std::weak_ptr<Widget> weak(shared);       // ref counter = 1 as before

    if (weak.expired()) {
        // not getting here
    }

    shared = nullptr;

    // We could check if weak_ptr is expired
    if (weak.expired()) {
        std::cout << "Expired" << std::endl;
    }

    // If weak is expired shared2 will be nullptr
    std::shared_ptr<Widget> shared2 = weak.lock(); 
    auto shared3 = weak.lock(); // same

    // But in this case an exception will be thrown
    //std::shared_ptr<Widget> shared4(weak);

    // Probable memory leak because compiler may shuffle the order in with arguments constructed
    processWidget(std::shared_ptr<Widget>(new Widget));
    processWidget(std::make_shared<Widget>()); // OK

    return 0;
}
