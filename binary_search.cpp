#include "log_duration.h"

#include <iostream>
#include <vector>

// https://stepik.org/lesson/13246/step/4

int binary_search(const std::vector<int>& sorted_vec, int k, bool indexes_from_one = false)
{
    int l = 0;
    int r = static_cast<int>(sorted_vec.size()) - 1;

    int m = 0;

    while (l <= r)
    {
        m = (l + r) / 2;

        if (sorted_vec[m] == k)
            return m + (indexes_from_one ? 1 : 0);
        else if (k < sorted_vec[m])
            r = m - 1;
        else
            l = m + 1;
    }

    return -1;
}

int main()
{
    int n;
    int k;

    std::cin >> n;

    std::vector<int> sorted_vec;
    sorted_vec.reserve(n);

    for (int i = 0; i < n; ++i)
    {
        int v;
        std::cin >> v;

        sorted_vec.push_back(v);
    }

    std::cin >> k;

    for (int i = 0; i < k; ++i)
    {
        int v;
        std::cin >> v;

        std::cout << binary_search(sorted_vec, v, true) << " ";
    }

    return 0;
}
