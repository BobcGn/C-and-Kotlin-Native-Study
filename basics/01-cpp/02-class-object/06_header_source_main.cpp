#include "user.hpp"

#include <iostream>

int main()
{
    User user(
        "Bob",
        20);

    std::cout
        << user.name()
        << ", "
        << user.age()
        << '\n';

    return 0;
}