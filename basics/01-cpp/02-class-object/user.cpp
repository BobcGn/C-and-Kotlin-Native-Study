#include "user.hpp"

User::User(
    std::string name,
    int age)
    : name_(name),
      age_(age)
{
}

const std::string &
User::name() const
{
    return name_;
}

int User::age() const
{
    return age_;
}

void User::set_age(
    int age)
{
    age_ = age;
}
