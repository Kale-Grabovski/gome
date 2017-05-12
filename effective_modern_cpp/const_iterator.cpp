#include <vector>
#include <iostream>
#include <algorithm>

template<typename C, typename V>
void findAndInsert(C& container, const V& targetVal, const V& insertVal) noexcept {
    using std::cbegin;
    using std::cend;

    // C++14 only
    auto it = std::find(cbegin(container), cend(container), targetVal);
    container.insert(it + 1, insertVal);
}

int main() {
    std::vector<int> years = {1983, 2003, 2011, 2014, 2017};
    findAndInsert(years, 1983, 1998);
    for (auto v : years) {
        std::cout << v << std::endl;
    }

    std::vector<std::string> names = {"John", "Mike"};
    findAndInsert(names, "John", "Homo");
    for (auto v : names) {
        std::cout << v << std::endl;
    }

    return 0;
}
