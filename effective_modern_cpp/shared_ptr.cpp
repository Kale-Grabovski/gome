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

Widget::widgets = std::vector<std::shared_ptr<Widget>>();

int main() {
    //crashed(); // fuck it

    Widget w, w1;
    w.process();
    w1.process();

    std::cout << "Hi" << std::endl;

    return 0;
}
