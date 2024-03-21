#include "log_duration.h"

#include <iostream>
#include <vector>

// https://stepik.org/lesson/13262/step/4

int stairs_sum(const std::vector<int>& numbers)
{
    if (numbers.size() == 1)
        return numbers.front();

    int prev_step = numbers[0];
    int current_step = std::max(numbers[0] + numbers[1], numbers[1]);

    int i = 2;

    while (i < numbers.size())
    {
        int next_step = std::max(current_step, prev_step) + numbers[i];

        prev_step = current_step;
        current_step = next_step;

        ++i;
    }

    return current_step;
}

int main()
{
    int n;

    std::cin >> n;

    std::vector<int> numbers;
    numbers.reserve(n);

    for (int i = 0; i < n; ++i)
    {
        int number;
        std::cin >> number;

        numbers.push_back(number);
    }

    std::cout << stairs_sum(numbers) << '\n';

    return 0;
}
