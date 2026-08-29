#include <iostream>
#include <string>

// 结构体 = Data + Behavior
struct User
{
    /* data */
    std::string name;
    int age;

    // C++中结构体可以有成员函数
    void print(){
        std::cout
            << "name = " << name
            << ", age = " << age
            << '\n';
    }
};

class User1{
    public:
        std::string name;
        int age;

        void print(){
            std::cout
                << "name = " << name
                << ", age = " << age
                << '\n';
        }

};
int main()
{
    User user{
        "Bob",
        20};

    user.print();

    User1 user1{
        "Bob",
        20};
    user1.print();

    return 0;
}
