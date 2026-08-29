#include <iostream>
#include <string>

class User{
public:
    // 构造函数（全参）
    // User(std::string name, int age){
    //     name_ = name;
    //     age_ = age;
    //     std::cout << "构造函数" << std::endl;
    // }
    User(std::string name, int age) : name_(name), age_(age){
        std::cout << "构造函数" << std::endl;
    }

    void print() const{
        std::cout
            << "name = " << name_
            << ", age = " << age_
            << '\n';
    }

    // 析构函数
    ~User(){
        std::cout << "析构函数" << std::endl;
    };

private:
    std::string name_;
    int age_;
};

int main()
{
    std::cout << "A\n";

    {
        std::cout << "B\n";

        User user(
            "Bob",
            20);

        std::cout << "C\n";
    }

    // 生命周期结束时销毁
    std::cout << "D\n";

    return 0;
}