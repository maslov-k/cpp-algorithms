#include "log_duration.h"

#include <iostream>
#include <vector>
#include <algorithm>

// https://stepik.org/lesson/41560/step/4

class DisjointSets
{
public:
    DisjointSets(int size)
    {
        for (int i = 0; i < size; ++i)
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
            return;

        _parents[parent_j] = parent_i;
    }

    bool is_set(int i, int j)
    {
        return find(i) == find(j);
    }

private:
    std::vector<int> _parents;
};

int main()
{
    int n;
    int e;
    int d;

    std::cin >> n;
    std::cin >> e;
    std::cin >> d;

    std::vector<int> tables_sizes;
    tables_sizes.reserve(n);

    DisjointSets set(n);

    for (int i = 0; i < e; ++i)
    {
        int x1;
        int x2;

        std::cin >> x1;
        std::cin >> x2;

        set.join(x1 - 1, x2 - 1);
    }

    bool result = true;

    for (int i = 0; i < d; ++i)
    {
        int x1;
        int x2;

        std::cin >> x1;
        std::cin >> x2;

        if (set.is_set(x1 - 1, x2 - 1))
        {
            result = false;
            break;
        }
    }

    std::cout << (result ? 1 : 0) << '\n';

    return 0;
}
