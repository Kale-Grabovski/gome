#include <tuple>
#include <iostream>
#include <string>

using User = std::tuple<std::string, int, float>;

// Pollutes the global scope but convenient to use in tuples for example
enum UserFields {uName, uAge, uReputation}; 

// Doesn't pollute the scope but getting info from the tuple is a nightmare
enum class ScopedUserFields {uName, uAge, uReputation}; 

int main() {
    User mike = std::make_tuple("Mike", 29, 0.1);

    // Short and OK
    std::cout << std::get<uAge>(mike) << " " << std::get<uName>(mike);

    // Long and not OK
    auto reputation = std::get<static_cast<std::size_t>(ScopedUserFields::uReputation)>(mike);
    std::cout << " " << reputation << std::endl;

    return 0;
}
