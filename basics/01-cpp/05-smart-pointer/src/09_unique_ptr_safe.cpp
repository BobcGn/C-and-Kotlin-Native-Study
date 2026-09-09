#include <iostream>
#include <memory>
#include <type_traits>

// 本步骤：定义由 unique_ptr 唯一拥有的最小资源类型。
class User
{
public:
    User()
    {
        // 构造日志表示资源生命周期开始。
        std::cout << "User created\n";
    }

    ~User() noexcept
    {
        // owner 离开作用域时，unique_ptr 自动触发唯一一次析构。
        std::cout << "User destroyed\n";
    }

    void hello() const
    {
        // 普通成员调用只借用对象，不改变 ownership。
        std::cout << "hello\n";
    }
};

// 本步骤：在编译期确认 unique ownership 不能复制，从类型层面排除双 owner。
static_assert(!std::is_copy_constructible_v<std::unique_ptr<User>>);
static_assert(!std::is_copy_assignable_v<std::unique_ptr<User>>);

int main()
{
    // 本步骤：使用 make_unique 创建唯一 owner，不暴露 owning raw pointer。
    auto user = std::make_unique<User>();

    // 对象只在当前 owner 生命周期内被借用。
    user->hello();

    // main 返回时 user 自动析构并释放 User，无需手写 delete。
    return 0;
}
