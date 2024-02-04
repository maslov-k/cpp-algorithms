#include "log_duration.h"

#include <iostream>
#include <vector>
#include <algorithm>

// https://stepik.org/lesson/13257/step/5

int len_of_longest_div_subseq(const std::vector<int>& vec)
{
    std::vector<int> d;
    d.reserve(vec.size());

    for (size_t i = 0, c = vec.size(); i < c; ++i)
    {
        d.push_back(1);

        for (size_t j = 0; j < i; ++j)
        {
            if (vec[i] % vec[j] == 0)
                d[i] = std::max(d[j] + 1, d[i]);
        }
    }

    return *std::max_element(d.begin(), d.end());
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> vec;
    vec.reserve(n);

    for (int i = 0; i < n; ++i)
    {
        int p;
        std::cin >> p;
        vec.push_back(p);
    }

    std::cout << len_of_longest_div_subseq(vec) << '\n';

    return 0;
}
