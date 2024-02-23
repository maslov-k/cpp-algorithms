#include "log_duration.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

// https://stepik.org/lesson/13258/step/8

int levenshtein_distance(std::string_view str1, std::string_view str2)
{
    std::vector<int> prev_row(str1.size() + 1);
    std::vector<int> curr_row(str1.size() + 1);

    std::iota(prev_row.begin(), prev_row.end(), 0);

    while(prev_row[0] < str2.size())
    {
        for (size_t i = 0, c = str1.size(); i <= c; ++i)
        {
            if (i == 0)
                curr_row[i] = prev_row[i] + 1;
            else
            {
                int diff = str1[i - 1] == str2[curr_row[0] - 1] ? 0 : 1;

                curr_row[i] = std::min({curr_row[i - 1] + 1, prev_row[i] + 1, prev_row[i - 1] + diff});
            }
        }

        std::swap(curr_row, prev_row);
    }

    return prev_row.back();
}

int main()
{
    std::string str1;
    std::string str2;

    std::cin >> str1 >> str2;

    std::cout << levenshtein_distance(str1, str2) << '\n';

    return 0;
}
