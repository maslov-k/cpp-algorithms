#include "log_duration.h"

#include <iostream>
#include <vector>
#include <algorithm>

// https://stepik.org/lesson/13257/step/6

//std::vector<size_t> longest_non_incr_subseq(const std::vector<int>& a) // n^2
//{
//    std::vector<int> d;
//    d.reserve(a.size());

//    for (size_t i = 0, c = a.size(); i < c; ++i)
//    {
//        d.push_back(1);

//        for (size_t j = 0; j < i; ++j)
//        {
//            if (a[i] <= a[j])
//                d[i] = std::max(d[j] + 1, d[i]);
//        }
//    }

//    int subseq_size = *std::max_element(d.begin(), d.end());

//    std::vector<size_t> subseq_indexes;
//    subseq_indexes.reserve(subseq_size);

//    int current_subseq_size = subseq_size;

//    size_t index = d.size();
//    while (current_subseq_size > 0 && index > 0)
//    {
//        --index;
//        if (d[index] == current_subseq_size && (subseq_indexes.empty() || a[index] >= a[subseq_indexes.back() - 1]))
//        {
//            subseq_indexes.push_back(index + 1);
//            --current_subseq_size;
//        }
//    }

//    std::reverse(subseq_indexes.begin(), subseq_indexes.end());

//    return subseq_indexes;
//}

std::vector<size_t> longest_non_incr_subseq(const std::vector<int>& a) // nlogn
{
    std::vector<int> d(a.size() + 1, -1);

    std::vector<int64_t> d_indexes(a.size() + 1, -1);
    std::vector<int64_t> prev_a(a.size(), -1);

    for (size_t i = 0, c = a.size(); i < c; ++i)
    {
        size_t j = std::upper_bound(std::next(d.begin()), d.end(), a[i], [](int el, int value)
        {
            return el > value;
        }) - d.begin();

        if ((a[i] <= d[j - 1] || j == 1) && a[i] > d[j])
        {
            d[j] = a[i];
            d_indexes[j] = i;
            prev_a[i] = d_indexes[j - 1];
        }
    }

    size_t subseq_len = std::prev(std::find(std::next(d.begin()), d.end(), -1)) - d.begin();
    int64_t current_index = d_indexes[subseq_len];

    std::vector<size_t> result;
    result.reserve(subseq_len);

    while (current_index != -1)
    {
        result.push_back(current_index + 1);

        current_index = prev_a[current_index];
    }

    std::reverse(result.begin(), result.end());

    return result;
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

    std::vector<size_t> subseq_indexes = longest_non_incr_subseq(vec);

    std::cout << subseq_indexes.size() << '\n';

    for (size_t i : subseq_indexes)
        std::cout << i << ' ';

    std::cout << '\n';

    return 0;
}
