#include "log_duration.h"

#include <iostream>
#include <vector>
#include <stack>
#include <cassert>

// https://stepik.org/lesson/41234/step/5

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
        return empty() ? 0 : _max.top();
    }

    const T& top()
    {
        return _stack.top();
    }

    bool empty()
    {
        return _stack.empty();
    }

    size_t size()
    {
        return _stack.size();
    }

private:
    std::stack<T> _stack;
    std::stack<T> _max;
};

template <typename T>
void move(StackWithMax<T>& from, StackWithMax<T>& to)
{
    while (!from.empty())
    {
        to.push(from.top());
        from.pop();
    }
}

template <typename T>
std::vector<T> sliding_window_maxs(const std::vector<T>& vec, size_t window_size)
{
    std::vector<T> result;
    result.reserve(vec.size() - window_size + 1);

    StackWithMax<T> inputStack;
    StackWithMax<T> outputStack;

    for (int i = window_size - 1; i >= 0; --i)
        outputStack.push(vec[i]);

    result.push_back(outputStack.max());

    for (size_t i = window_size, c = vec.size(); i < c; ++i)
    {
        if (inputStack.size() == window_size)
            move(inputStack, outputStack);

        inputStack.push(vec[i]);
        outputStack.pop();

        result.push_back(std::max(inputStack.max(), outputStack.max()));
    }

    return result;
}

void test()
{
    assert(sliding_window_maxs(std::vector<int>{2, 7, 3, 1, 5, 2, 6, 2}, 4) == std::vector<int>({7, 7, 5, 6, 6}));
    assert(sliding_window_maxs(std::vector<int>{2, 1, 5}, 1) == std::vector<int>({2, 1, 5}));
    assert(sliding_window_maxs(std::vector<int>{2, 3, 9}, 3) == std::vector<int>({9}));
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> vec;
    vec.reserve(n);

    for (int i = 0; i < n; ++i)
    {
        int v;
        std::cin >> v;

        vec.push_back(v);
    }

    size_t w;
    std::cin >> w;

    std::vector<int> maxs = sliding_window_maxs(vec, w);

    for (int i : maxs)
        std::cout << i << ' ';

    std::cout << '\n';

    return 0;
}
