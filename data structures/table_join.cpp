#include "log_duration.h"

#include <iostream>
#include <vector>
#include <algorithm>

// https://stepik.org/lesson/41560/step/3

class Tables
{
public:
    Tables(std::vector<int>&& sizes)
        : _sizes(sizes)
        , _max_size(*std::max_element(_sizes.begin(), _sizes.end()))
    {
        _parents.reserve(_sizes.size());

        for (size_t i = 0, c = _sizes.size(); i < c; ++i)
            _parents.push_back(i);
    }

    int find(int i)
    {
        if (i != _parents[i])
            _parents[i] = find(_parents[i]);

        return _parents[i];
    }

    void join(int i, int j)
    {
        int parent_i = find(i);
        int parent_j = find(j);

        if (parent_i == parent_j)
        {
            std::cout << _max_size << '\n';
            return;
        }

        _sizes[parent_i] += _sizes[parent_j];

        _max_size = std::max(_max_size, _sizes[parent_i]);
        _sizes[parent_j] = 0;

        _parents[parent_j] = parent_i;

        std::cout << _max_size << '\n';
    }

private:
    std::vector<int> _parents;
    std::vector<int> _sizes;

    int _max_size;
};

int main()
{
    int n;
    int m;

    std::cin >> n;
    std::cin >> m;

    std::vector<int> tables_sizes;
    tables_sizes.reserve(n);

    for (int i = 0; i < n; ++i)
    {
        int size;
        std::cin >> size;

        tables_sizes.push_back(size);
    }

    Tables tables(std::move(tables_sizes));

    for (int i = 0; i < m; ++i)
    {
        int dest;
        int src;

        std::cin >> dest;
        std::cin >> src;

        tables.join(dest - 1, src - 1);
    }

    return 0;
}
