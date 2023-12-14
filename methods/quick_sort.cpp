#include "log_duration.h"

#include <iostream>
#include <vector>
#include <random>
#include <tuple>

// quick_sort + quick3_sort

template <typename Int>
int random_number(Int l, Int r)
{
    static std::random_device rd;
    static std::mt19937 generator(rd());

    return std::uniform_int_distribution<Int>(l, r)(generator);
}

template <typename Int>
int partition(std::vector<Int>& vec, int l, int r)
{
    int rand = random_number(l, r);
    std::swap(vec[l], vec[rand]);

    int x = vec[l];

    int j = l;

    for (int i = l + 1; i <= r; ++i)
    {
        if (vec[i] <= x)
        {
            ++j;
            std::swap(vec[i], vec[j]);
        }
    }

    std::swap(vec[l], vec[j]);

    return j;
}

template <typename Int>
void quick_sort(std::vector<Int>& vec, int l = 0, int r = -1)
{
    if (r == -1)
        r = static_cast<int>(vec.size()) - 1;

    while (l < r)
    {
        int m = partition(vec, l, r);

        if (m - l > r - m)
        {
            quick_sort(vec, l, m - 1);
            l = m + 1;
        }
        else
        {
            quick_sort(vec, m + 1, r);
            r = m - 1;
        }
    }
}

template <typename Int>
std::tuple<Int, Int> partition3(std::vector<Int>& vec, int l, int r)
{
    int rand = random_number(l, r);
    std::swap(vec[l], vec[rand]);

    int x = vec[l];

    int j = l;

    for (int i = l + 1; i <= r; ++i)
    {
        if (vec[i] < x)
        {
            ++j;

            std::swap(vec[i], vec[j]);
        }
    }

    std::swap(vec[l], vec[j]);

    int k = j;

    for (int i = j + 1; i <= r; ++i)
    {
        if (vec[i] == x)
        {
            ++k;

            std::swap(vec[i], vec[k]);
        }
    }

    return {j, k};
}

template <typename Int>
void quick3_sort(std::vector<Int>& vec, int l = 0, int r = -1)
{
    if (r == -1)
        r = static_cast<int>(vec.size()) - 1;

    while (l < r)
    {
        Int m1;
        Int m2;
        std::tie(m1, m2) = partition3(vec, l, r);

        if (m1 - l > r - m2)
        {
            quick3_sort(vec, l, m1 - 1);
            l = m2 + 1;
        }
        else
        {
            quick3_sort(vec, m2 + 1, r);
            r = m1 - 1;
        }
    }
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

    quick_sort(vec);
//    quick3_sort(vec);
}
