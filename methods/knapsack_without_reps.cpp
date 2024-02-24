#include "log_duration.h"

#include <iostream>
#include <vector>
#include <string>

int knapsack_without_reps(int capacity, const std::vector<int>& weights, const std::vector<int>& costs)
{
    std::vector<std::vector<int>> d(capacity + 1, std::vector<int>(weights.size() + 1, 0));

    for (size_t i = 1, c = weights.size(); i <= c; ++i)
    {
        for (int w = 1; w <= capacity; ++w)
        {
            d[w][i] = d[w][i - 1];

            if (weights[i - 1] <= w)
                d[w][i] = std::max(d[w][i], d[w - weights[i - 1]][i - 1] + costs[i - 1]);
        }
    }

    return d[capacity][weights.size()];
}

int main()
{
    int w;
    int n;

    std::cin >> w >> n;

    std::vector<int> weights;
    weights.reserve(n);

    for (int i = 0; i < n; ++i)
    {
        int weight;
        std::cin >> weight;

        weights.push_back(weight);
    }

    std::cout << knapsack_without_reps(w, weights, weights) << '\n';

    return 0;
}
