#include "log_duration.h"

#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

// https://stepik.org/lesson/13238/step/9

std::vector<int> get_covering_set(std::vector<std::pair<int, int>>&& segments)
{
    assert(segments.size() > 0);

    std::vector<int> result;

    std::sort(segments.begin(), segments.end(), [](const std::pair<int, int>& l, const std::pair<int, int>& r)
              {
                  return l.second < r.second;
              });

    result.push_back(segments.front().second);

    for (auto s : segments)
    {
        if (result.back() >= s.first)
            continue;
        else
            result.push_back(s.second);
    }

    return result;
}

int main()
{
    int segments_count;
    std::cin >> segments_count;

    std::vector <std::pair<int, int>> segments(segments_count);

    for (auto& s : segments)
    {
        std::cin >> s.first >> s.second;
    }

    std::vector<int> points = get_covering_set(std::move(segments));

    std::cout << points.size() << std::endl;

    for (int point : points)
    {
        std::cout << point << ' ';
    }

    std::cout << std::endl;

    return 0;
}
