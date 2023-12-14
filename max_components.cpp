#include "log_duration.h"

#include <iostream>
#include <vector>

//https://stepik.org/lesson/13238/step/11

std::vector<int> get_max_different_components(int n)
{
    std::vector<int> result;

    for (int i = 1; n > i * 2; ++i)
    {
        result.push_back(i);

        n -= i;
    }

    result.push_back(n);

    return result;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> components = get_max_different_components(n);

    std::cout << components.size() << std::endl;

    for (int i : components)
        std::cout << i << ' ';

    std::cout << std::endl;

    return 0;
}
