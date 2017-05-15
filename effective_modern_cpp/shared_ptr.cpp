#include <memory>
#include <iostream>
#include <vector>

class Investment {};

void crashed() {
    Investment* inv = new Investment();

    {
        std::shared_ptr<Investment> inv_ptr(inv);
    } // Remove pointer here

    // Crashed here =)
    std::shared_ptr<Investment> inv_ptr2(inv);
}


class Widget : public std::enable_shared_from_this<Widget> {
public:
    void process() {
        widgets.emplace_back(shared_from_this());
    }
    
    static std::vector<std::shared_ptr<Widget>> widgets;
};

std::vector<std::shared_ptr<Widget>> Widget::widgets;

int main() {
    //crashed(); // fuck it

    // If we declare these vars as usual pointer the program will crash at runtime,
    // because shared_from_this() only worked with shared_ptr-s
    auto w1 = std::make_shared<Widget>();
    auto w2 = std::make_shared<Widget>();

    w1->process();
    w2->process();

    std::cout << "Hi" << std::endl;

    return 0;
}
