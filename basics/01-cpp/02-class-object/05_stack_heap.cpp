#include <iostream>

class User
{
public:
    User()
    {
        std::cout
            << "constructor\n";
    }

    ~User()
    {
        std::cout
            << "destructor\n";
    }
};

int main()
{
    std::cout
        << "stack object\n";

    // 栈对象 进入生命周期 -- 构造 -- 使用 -- 结束生命周期 -- 析构
    User stack_user;

    std::cout
        << "heap object\n";

    // 堆对象  分配内存 -- 构造 -- 返回指针 -- 删除指针（释放内存）
    User *heap_user = new User;

    std::cout
        << "delete heap object\n";

    delete heap_user; // 堆对象必须手动释放，否则会出现内存泄露

    std::cout
        << "end\n";

    return 0;
}