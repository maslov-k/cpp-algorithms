#include "log_duration.h"

#include <iostream>
#include <vector>
#include <queue>

// recursive + iterative merge sort

template <typename Int>
std::vector<Int> merge(const std::vector<Int>& vec_l, const std::vector<Int>& vec_r)
{
    std::vector<Int> result;
    result.reserve(vec_l.size() + vec_r.size());

    auto it_l = vec_l.begin();
    auto it_r = vec_r.begin();

    while (it_l != vec_l.end() || it_r != vec_r.end())
    {
        if (it_l == vec_l.end())
        {
            result.push_back(*it_r);
            ++it_r;
        }
        else if (it_r == vec_r.end())
        {
            result.push_back(*it_l);
            ++it_l;
        }
        else if (*it_l < *it_r)
        {
            result.push_back(*it_l);
            ++it_l;
        }
        else
        {
            result.push_back(*it_r);
            ++it_r;
        }
    }

    return result;
}

template <typename Int>
std::vector<Int> iterative_merge_sort(const std::vector<Int>& vec)
{
    std::queue<std::vector<Int>> result;

    for (Int i : vec)
    {
        result.push(std::vector<Int>{i});
    }

    while (result.size() > 1)
    {
        std::vector<Int> vec_1 = std::move(result.front());
        result.pop();
        std::vector<Int> vec_2 = std::move(result.front());
        result.pop();
        result.push(merge(vec_1, vec_2));
    }

    return result.empty() ? std::vector<Int>{} : result.front();
}

template <typename Int>
std::vector<Int> merge_sort(const std::vector<Int>& vec, size_t l = 0, size_t r = -1)
{
    if (vec.empty())
    {
        return vec;
    }

    if (r == -1)
    {
        r = vec.size() - 1;
    }

    if (l < r)
    {
        size_t m = (l + r) / 2;

        return merge(merge_sort(vec, l, m), merge_sort(vec, m + 1, r));
    }

    return {vec[l]};
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> unsorted_vec;
    unsorted_vec.reserve(n);

    for (int i = 0; i < n; ++i)
    {
        int v;
        std::cin >> v;

        unsorted_vec.push_back(v);
    }

    std::vector<int> sorted_vec = iterative_merge_sort(unsorted_vec);
//    std::vector<int> sorted_vec = merge_sort(unsorted_vec);

    for (int v : sorted_vec)
    {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    return 0;
}
