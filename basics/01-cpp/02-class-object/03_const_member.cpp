#include <iostream>
#include <string>

class User{
public:
    User(std::string name,int age): name_(name),age_(age){}

    // getter & setter
    const std::string& name() const{
        return name_;
    }

    int age() const{
        return age_;
    }

    void set_age(int age){
        age_ = age;
    }

    

    private:
        std::string name_;
        int age_;
};

void print_user(const User &user){
    std::cout
        << user.name()
        << ", "
        << user.age()
        << '\n';
}

int main()
{
    User user(
        "Bob",
        20);

    print_user(user);

    user.set_age(21);

    print_user(user);

    return 0;
}