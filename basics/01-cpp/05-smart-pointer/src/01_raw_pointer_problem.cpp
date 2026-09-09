#include <cassert>
#include <iostream>

// 本步骤：定义带生命周期日志的对象，让构造、析构和泄漏都可观察。
class User
{
public:
    explicit User(int id)
        : id_(id)
    {
        // 构造完成后增加存活计数，表示堆上已经存在一个 User。
        ++live_count_;
        std::cout << "User " << id_ << " created, live = " << live_count_ << '\n';
    }

    ~User() noexcept
    {
        // 析构时减少计数；若没有看到这条日志，说明清理路径没有执行。
        --live_count_;
        std::cout << "User " << id_ << " destroyed, live = " << live_count_ << '\n';
    }

    static int live_count() noexcept
    {
        // 只读返回当前存活数量，供实验断言使用。
        return live_count_;
    }

private:
    int id_;
    inline static int live_count_ = 0;
};

// 本步骤：实现手动管理版本，并故意保留一条跳过 delete 的提前返回路径。
void process_raw(bool early_return)
{
    // new 在堆上创建对象；此刻 user 被人为约定为唯一 owner。
    User *user = new User(1);

    // 提前返回会丢失唯一地址，但不会自动销毁堆上的 User。
    if (early_return)
    {
        std::cout << "early return: delete is skipped\n";
        return;
    }

    // 只有正常路径执行到这里时，对象才会被释放。
    delete user;

    // delete 后原地址已经失效；置空只避免本变量被误用。
    user = nullptr;
}

int main()
{
    // 本步骤：先运行正常路径，确认一次 new 对应一次 delete。
    const int before_normal_path = User::live_count();
    process_raw(false);
    assert(User::live_count() == before_normal_path);

    // 本步骤：再触发提前返回，故意留下一个供 LeakSanitizer 检测的对象。
    const int before_early_return = User::live_count();
    process_raw(true);
    assert(User::live_count() == before_early_return + 1);

    // 最后输出现象；程序故意不补救泄漏，否则 Sanitizer 将无法复现问题。
    std::cout << "leaked objects in this run = 1\n";
    return 0;
}
