#include "log_duration.h"

#include <iostream>
#include <cassert>
#include <utility>
#include <vector>
#include <algorithm>

// gcd ------------------------------------------------------------------------------------------------------------------------------------

//template <class Int>
//Int gcd(Int a, Int b)
//{
//    while (a > 0 && b > 0)
//    {
//        if (a > b)
//            a %= b;
//        else
//            b %= a;
//    }

//    return a == 0 ? b : a;
//}

// covering set ------------------------------------------------------------------------------------------------------------------------------------

//std::vector<int> get_covering_set(std::vector<std::pair<int, int>>&& segments)
//{
//    assert(segments.size() > 0);

//    std::vector<int> result;

//    std::sort(segments.begin(), segments.end(), [](const std::pair<int, int>& l, const std::pair<int, int>& r)
//              {
//                  return l.second < r.second;
//              });

//    result.push_back(segments.front().second);

//    for (auto s : segments)
//    {
//        if (result.back() >= s.first)
//            continue;
//        else
//            result.push_back(s.second);
//    }

//    return result;
//}

//int main()
//{
//    int segments_count;
//    std::cin >> segments_count;

//    std::vector <std::pair<int, int>> segments(segments_count);

//    for (auto& s : segments)
//    {
//        std::cin >> s.first >> s.second;
//    }

//    std::vector<int> points = get_covering_set(std::move(segments));

//    std::cout << points.size() << std::endl;

//    for (int point : points)
//    {
//        std::cout << point << " ";
//    }

//    std::cout << std::endl;

//    return 0;
//}

// max knapsack value ------------------------------------------------------------------------------------------------------------------------------------

struct Item
{
    int weight;
    int value;
};

double get_max_knapsack_value(int capacity, std::vector<Item>&& items)
{
    double result = 0.0;

    std::sort(items.begin(), items.end(), [](const Item& l, const Item& r)
              {
                  return l.value * 1. / l.weight > r.value * 1. / r.weight;
              });

    for (auto& item : items)
    {
        if (capacity > item.weight)
        {
            capacity -= item.weight;
            result += item.value;
        }
        else
        {
            result += item.value * (static_cast <double>(capacity) / item.weight);
            break;
        }
    }

    return result;
}

int main(void)
{
    int number_of_items;
    int knapsack_capacity;

    std::cin >> number_of_items >> knapsack_capacity;

    std::vector<Item> items(number_of_items);

    for (int i = 0; i < number_of_items; i++)
        std::cin >> items[i].value >> items[i].weight;

    double max_knapsack_value = get_max_knapsack_value(knapsack_capacity, std::move(items));

    std::cout.precision(10);
    std::cout << max_knapsack_value << std::endl;

    return 0;
}
