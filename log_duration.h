#include <chrono>
#include <iostream>

class LogDuration
{
public:
    LogDuration()
    {}

    ~LogDuration()
    {
        const auto end_time = std::chrono::steady_clock::now();
        const auto dur = end_time - start_time_;

        std::cerr << std::chrono::duration_cast<std::chrono::milliseconds>(dur).count() << " ms" << std::endl;
    }

private:
    const std::chrono::steady_clock::time_point start_time_ = std::chrono::steady_clock::now();
};
