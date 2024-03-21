#include "log_duration.h"

#include <iostream>
#include <vector>
#include <algorithm>

// https://stepik.org/lesson/13262/step/5

int prev_index(const std::vector<int>& vec, int curr_index)
{
    int result = curr_index - 1;

    if (curr_index % 2 == 0 && vec[curr_index / 2] < vec[result])
        result = curr_index / 2;

    if (curr_index % 3 == 0 && vec[curr_index / 3] < vec[result])
        result = curr_index / 3;

    return result;
}

std::vector<int> calculations(int n)
{
    std::vector<int> calculated(n + 1, -1);
    std::vector<int> prev(n + 1, 0);

    for (int i = 1; i <= n; ++i)
    {
        if (i == 1)
            calculated[i] = 0;
        else if (i < 4)
            calculated[i] = 1;
        else
        {
            prev[i] = prev_index(calculated, i);
            calculated[i] = calculated[prev[i]] + 1;
        }
    }

    int calc_result = n;

    std::vector<int> sequence;
    sequence.reserve(calculated.back() + 1);

    while (calculated[calc_result] > 0)
    {
        sequence.push_back(calc_result);
        calc_result = prev[calc_result];
    }

    sequence.push_back(1);

    std::reverse(sequence.begin(), sequence.end());

    return sequence;
}

int main()
{
    int n;

    std::cin >> n;

    std::vector<int> sequence = calculations(n);

    std::cout << sequence.size() - 1 << '\n';

    for (int el : sequence)
        std::cout << el << ' ';

    std::cout << '\n';

    return 0;
}
