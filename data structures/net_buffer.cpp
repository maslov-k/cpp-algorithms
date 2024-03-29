#include "log_duration.h"

#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

// https://stepik.org/lesson/41234/step/3

struct Package
{
    int arival     =  0;
    int duration   =  0;
    int start_time = -1;
};

using Packages = std::vector<Package>;

void process(Packages& packages, int buffer_size)
{
    std::queue<Package*> queue;

    int time = 0;

    for (Package& package : packages)
    {
        time = package.arival;

        while (!queue.empty() && queue.front()->start_time + queue.front()->duration <= time)
            queue.pop();

        if (queue.size() < buffer_size)
        {
            package.start_time = queue.empty() ? time : queue.back()->start_time + queue.back()->duration;

            queue.push(&package);
        }
    }
}

int main()
{
    int buffer_size;
    int n;

    std::cin >> buffer_size >> n;

    Packages packages;
    packages.reserve(n);

    for (int i = 0; i < n; ++i)
    {
        Package package;
        std::cin >> package.arival;
        std::cin >> package.duration;

        packages.push_back(package);
    }

    process(packages, buffer_size);

    for (const Package& package : packages)
        std::cout << package.start_time << '\n';

    return 0;
}
