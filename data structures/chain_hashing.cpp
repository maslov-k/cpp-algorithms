#include "log_duration.h"

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

// https://stepik.org/lesson/41562/step/2

class ChainHasher
{
public:
    ChainHasher(int table_size)
        : _table(table_size)
    {}

public:
    void add(std::string_view str)
    {
        std::list<std::string>& chain = _table[hash(str)];

        if (std::find(chain.begin(), chain.end(), str) == chain.end())
            chain.push_front(std::string(str));
    }

    void del(std::string_view str)
    {
        std::list<std::string>& chain = _table[hash(str)];

        auto it = std::find(chain.begin(), chain.end(), str);
        if (it != chain.end())
            chain.erase(it);
    }

    void find(std::string_view str)
    {
        std::list<std::string>& chain = _table[hash(str)];

        auto it = std::find(chain.begin(), chain.end(), str);

        std::cout << (it != chain.end() ? "yes" : "no") << '\n';
    }

    void check(int i)
    {
        const std::list<std::string>& chain = _table[i];

        for (std::string_view str : chain)
            std::cout << str << ' ';

        std::cout << '\n';
    }

private:
    int64_t hash(std::string_view str)
    {
        int p = 1000000007;
        int64_t x = 1;

        int64_t result = 0;

        for (size_t i = 0, c = str.size(); i < c; ++i)
        {
            result += str[i] * x;
            result %= p;

            x = (x * 263) % p;
        }

        result %= _table.size();

        return result;
    }

private:
    std::vector<std::list<std::string>> _table;
};

int main()
{
    int m;
    int n;

    std::cin >> m;
    std::cin >> n;

    ChainHasher hasher(m);

    for (int i = 0; i < n; ++i)
    {
        std::string cmd;

        std::cin >> cmd;

        if (cmd == "add")
        {
            std::string str;

            std::cin >> str;

            hasher.add(str);
        }
        else if (cmd == "find")
        {
            std::string str;

            std::cin >> str;

            hasher.find(str);
        }
        else if (cmd == "del")
        {
            std::string str;

            std::cin >> str;

            hasher.del(str);
        }
        else if (cmd == "check")
        {
            int index;

            std::cin >> index;

            hasher.check(index);
        }
    }

    return 0;
}
