#include "log_duration.h"

#include <iostream>
#include <stack>
#include <string>

// https://stepik.org/lesson/41234/step/4

template <typename T>
class StackWithMax
{
public:
    StackWithMax()
    {}

public:
    void push(const T& v)
    {
        _stack.push(v);
        _max.push(_max.empty() ? v : std::max(v, _max.top()));
    }

    void pop()
    {
        _stack.pop();
        _max.pop();
    }

    T max()
    {
        return _max.top();
    }

private:
    std::stack<T> _stack;
    std::stack<T> _max;
};

int main()
{
    int n;

    std::cin >> n;

    StackWithMax<int> stack;

    for (int i = 0; i < n; ++i)
    {
        std::string cmd;
        std::cin >> cmd;

        if (cmd == "push")
        {
            int v;
            std::cin >> v;

            stack.push(v);
        }
        else if (cmd == "pop")
            stack.pop();
        else if (cmd == "max")
            std::cout << stack.max() << '\n';
    }

    return 0;
}
