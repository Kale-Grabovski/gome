#include <iostream>
#include <vector>
#include <mutex>

class Polynom {
    public:
    using RootsType = std::vector<double>;

    RootsType roots() const {
        std::lock_guard<std::mutex> g(m);

        if (!rootsValid) {
            rootsValid = true;
            rootVals = {1.0, 2.0};
        }

        return rootVals;
    }

    private:
    mutable std::mutex m;
    mutable bool rootsValid {false};
    mutable RootsType rootVals {};
};

int main() {
    Polynom p;

    for (auto r : p.roots()) {
        std::cout << r << std::endl;
    }

    return 0;
}
