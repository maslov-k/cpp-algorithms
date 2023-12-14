#include "log_duration.h"

#include <iostream>
#include <vector>
#include <queue>

// https://stepik.org/lesson/13248/step/5
// by merge sort

template <typename Int>
std::vector<Int> merge(const std::vector<Int>& vec_l, const std::vector<Int>& vec_r, int64_t& inversions_count)
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

            inversions_count += std::distance(it_l, vec_l.end());
        }
        else if (it_r == vec_r.end())
        {
            result.push_back(*it_l);
            ++it_l;
        }
        else if (*it_l <= *it_r)
        {
            result.push_back(*it_l);
            ++it_l;
        }
        else
        {
            result.push_back(*it_r);
            ++it_r;

            inversions_count += std::distance(it_l, vec_l.end());
        }
    }

    return result;
}

template <typename Int>
std::vector<Int> merge_sort(const std::vector<Int>& vec, int64_t& inversions_count, size_t l = 0, size_t r = -1)
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

        return merge(merge_sort(vec, inversions_count, l, m), merge_sort(vec, inversions_count, m + 1, r), inversions_count);
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

    int64_t inversions_count = 0;

    std::vector<int> sorted_vec = merge_sort(unsorted_vec, inversions_count);

    std::cout << inversions_count << std::endl;

    return 0;
}
