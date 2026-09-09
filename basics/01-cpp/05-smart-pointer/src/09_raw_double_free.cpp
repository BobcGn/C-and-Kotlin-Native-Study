#include <iostream>

// 本步骤：定义最小资源类型，让构造与第一次析构可观察。
class User
{
public:
    User()
    {
        // 构造日志表示堆对象生命周期开始。
        std::cerr << "User created\n";
    }

    ~User() noexcept
    {
        // 第一次 delete 会调用析构；第二次 delete 已属于未定义行为。
        std::cerr << "User destroyed\n";
    }
};

int main()
{
    // 本步骤：使用 owning raw pointer 创建一个需要手动释放的 User。
    User *user = new User;

    // 第一次 delete 正常结束 User 生命周期并释放内存。
    delete user;

    // 本步骤：故意再次释放同一悬空地址，供 AddressSanitizer 检测 double-free。
    std::cerr << "deleting the same address again\n";
    delete user;

    // 程序通常会在第二次 delete 时被 Sanitizer 终止，无法执行到这里。
    return 0;
}
