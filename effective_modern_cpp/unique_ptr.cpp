#include <memory>
#include <iostream>

class Investment {
public:
    Investment(int ii) : i(ii) {}
    Investment(int ii, int kk) : i(ii), k(kk) {}
    virtual ~Investment() {}

    void print() { std::cout << i << " " << k << std::endl; }

protected:
    int i{0};
    int k{0};
};

class Bond : public Investment {
public:
    Bond(int ii) : Investment(ii) {}
    Bond(int ii, int kk) : Investment(ii, kk) {}
};

class Stock : public Investment {
public:
    Stock(int ii) : Investment(ii) {}
    Stock(int ii, int kk) : Investment(ii, kk) {}
};

// Fabric, C++14
template<typename T, typename... Args>
auto makeUnique(Args&&... args) {
    // Custom delete method, C++14
    auto delInvestment = [](Investment* pInvestment) {
        std::cout << "Delete Investment ptr " << pInvestment << std::endl;
        delete pInvestment;
    };

    std::unique_ptr<T, decltype(delInvestment)> pInv(nullptr, delInvestment);
    pInv.reset(new T(std::forward<Args>(args)...));

    return pInv;
}

int main() {
    // Here is auto deduct the type as std::unique_ptr, but it could also be easily converted into std::shared_ptr
    auto bond = makeUnique<Bond>(666);
    bond->print();

    auto stock = makeUnique<Stock>(666, 777);
    stock->print();

    return 0;
}
