#ifndef USER_HPP
#define USER_HPP

#include <string>
// 声明
class User
{
public:
    User(
        std::string name,
        int age);

    const std::string &name() const;

    int age() const;

    void set_age(int age);

private:
    std::string name_;
    int age_;
};


#endif