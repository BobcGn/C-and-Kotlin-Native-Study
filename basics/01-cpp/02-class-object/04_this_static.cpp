#include <iostream>

class Counter
{
public:
    void print_address() const
    {
        std::cout
            << "this = "
            << this
            << '\n';
    }

    Counter()
    {
        ++count_;
    }

    ~Counter()
    {
        --count_;
    }

    static int count()
    {
        return count_;
    }

private:
    static inline int count_ = 0;
};

int main()
{
    std::cout
        << Counter::count()
        << '\n';

    Counter a;

    std::cout
        << Counter::count()
        << '\n';

    {
        Counter b;

        std::cout
            << Counter::count()
            << '\n';
    }

    std::cout
        << Counter::count()
        << '\n';

    return 0;
}
