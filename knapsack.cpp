#include "log_duration.h"

#include <iostream>

#include <vector>
#include <algorithm>

// https://stepik.org/lesson/13238/step/10

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
        return l.value * 1. / l.weight > r.value * 1. / r.weight; // можно заменить умножением для увеличения быстродействия
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

int main()
{
    std::ios_base::sync_with_stdio(false);

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
