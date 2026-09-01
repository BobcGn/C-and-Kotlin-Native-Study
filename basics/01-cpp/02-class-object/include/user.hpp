#ifndef KOTLIN_NATIVE_STUDY_USER_HPP
#define KOTLIN_NATIVE_STUDY_USER_HPP

#include <string>

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

#endif // KOTLIN_NATIVE_STUDY_USER_HPP
