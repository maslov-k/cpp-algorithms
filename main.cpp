#include <chrono>
#include <cassert>
#include <cstdint>
#include <iostream>

class LogDuration
{
public:
    LogDuration() {
    }
    ~LogDuration() {
        const auto end_time = std::chrono::steady_clock::now();
        const auto dur = end_time - start_time_;

        std::cerr << std::chrono::duration_cast<std::chrono::milliseconds>(dur).count() << " ms" << std::endl;
    }
private:
    const std::chrono::steady_clock::time_point start_time_ = std::chrono::steady_clock::now();
};

template <class Int>
Int gcd(Int a, Int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
            a %= b;
        else
            b %= a;
    }

    return a == 0 ? b : a;
}

int main()
{
    int64_t n;
    int64_t m;
    std::cin >> n >> m;

    LogDuration log_duration;

    std::cout << gcd(n, m) << std::endl;

    return 0;
}
