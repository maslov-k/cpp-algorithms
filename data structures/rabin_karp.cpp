#include "log_duration.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// https://stepik.org/lesson/41562/step/3

namespace
{

int64_t mod(int64_t a, int64_t b)
{
    double x = static_cast<double>(a) / b;
    return a - std::floor(x) * b;
}

} // namespace

class RabinKarp
{
public:
    RabinKarp(std::string_view text, std::string_view pattern)
        : _text(text)
        , _pattern(pattern)
    {
        _pattern_hash = hash(_pattern);

        _last_x = 1;

        for (size_t i = 1, c = _pattern.size(); i < c; ++i)
        {
            _last_x *= _x;
            _last_x %= _p;
        }
    }

    std::vector<int> entries()
    {
        std::vector<int> result;

        int pattern_size = static_cast<int>(_pattern.size());

        int last_index = static_cast<int>(_text.size()) - pattern_size;

        int64_t prev_hash = 0;

        for (int i = last_index; i >= 0; --i)
        {
            if (i == last_index)
                prev_hash = hash(_text, i, i + pattern_size);
            else
                prev_hash = ((mod(prev_hash - _text[i + pattern_size] * _last_x, _p) * _x) % _p + _text[i]) % _p;

            if (prev_hash == _pattern_hash && is_entry(i))
                result.push_back(i);
        }

        return result;
    }

private:
    int64_t hash(std::string_view str, int start = -1, int end = -1)
    {
        if (start == -1)
            start = 0;

        if (end == -1)
            end = static_cast<int>(str.size());

        int64_t x = 1;

        int64_t result = 0;

        for (int i = start; i < end; ++i)
        {
            result = (result + str[i] * x) % _p;

            x = x * _x % _p;
        }

        return result;
    }

    bool is_entry(int index)
    {
        for (size_t i = 0, c = _pattern.size(); i < c; ++i)
        {
            if (_pattern[i] != _text[i + index])
                return false;
        }

        return true;
    }

private:
    std::string_view _text;
    std::string_view _pattern;

    int64_t _pattern_hash;

    int _p = 1000000007;
    int _x = 263;
    int64_t _last_x;
};


int main()
{
    std::string pattern;
    std::string text;

    std::cin >> pattern;
    std::cin >> text;

    RabinKarp rk(text, pattern);

    std::vector<int> entries = rk.entries();

    for (auto it = entries.rbegin(), e = entries.rend(); it != e; ++it)
        std::cout << *it << ' ';

    std::cout << '\n';

    return 0;
}
