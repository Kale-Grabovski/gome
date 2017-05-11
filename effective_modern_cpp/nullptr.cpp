#include <memory>
#include <mutex>

template<typename FuncType, typename MuxType, typename PtrType>
decltype (auto) lockAndCall(FuncType func, MuxType& mutex, PtrType ptr) {
    using MuxGuard = std::lock_guard<MuxType>;
    MuxGuard g(mutex);
    return func(ptr);
}

class Widget {};

int f1(std::shared_ptr<Widget> spw) {}
double f2(std::unique_ptr<Widget> upw) {}
bool f3(Widget* pw) {}

int main() {
    std::mutex f1m, f2m, f3m;

    //auto result1 = lockAndCall(f1, f1m, 0); // Error - could not convert ‘ptr’ from ‘long int’ to ‘std::unique_ptr<Widget>’
    //auto result2 = lockAndCall(f2, f2m, NULL); // Error - same
    auto result3 = lockAndCall(f3, f3m, nullptr); // OK

    return 0;
}
