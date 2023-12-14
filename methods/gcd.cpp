#include "log_duration.h"

#include <iostream>

template <typename Int>
Int gcd(Int a, Int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
            a %= b;
        else
            b %= a;
    }

    return a == 0 ? b : a;
}

int main()
{
    int a;
    int b;

    std::cin >> a;
    std::cin >> b;

    std::cout  << gcd(a, b) << '\n';

    return 0;
}
