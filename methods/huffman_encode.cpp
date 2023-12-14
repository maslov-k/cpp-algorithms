#include "log_duration.h"

#include <iostream>
#include <cassert>
#include <unordered_map>
#include <set>

// https://stepik.org/lesson/13239/step/5

void make_node(std::set<std::pair<int, std::string>>& heap, std::unordered_map<char, std::string>& code_map)
{
    assert(heap.size() > 1);

    auto min_1 = heap.begin();

    for (char c : min_1->second)
        code_map[c].insert(0, "0");

    auto min_2 = std::next(heap.begin());

    for (char c : min_2->second)
        code_map[c].insert(0, "1");

    std::pair<int, std::string> new_node{min_1->first + min_2->first, min_1->second + min_2->second};

    heap.erase(min_1);
    heap.erase(min_2);

    heap.insert(std::move(new_node));
}

int main()
{
    std::string s;
    std::cin >> s;

    std::unordered_map<char, int> freqs;

    for (char c : s)
    {
        if (freqs.find(c) == freqs.end())
            freqs[c] = 1;
        else
            ++freqs[c];
    }

    std::set<std::pair<int, std::string>> freqsSet;

    for (auto i = freqs.begin(); i != freqs.end(); ++i)
    {
        freqsSet.emplace(std::pair<int, std::string>(i->second, std::string{i->first}));
    }

    std::unordered_map<char, std::string> code_map;

    if (freqs.size() == 1)
        code_map[s[0]] = "0";

    while (freqsSet.size() > 1)
        make_node(freqsSet, code_map);

    std::string result_str;

    for (char c : s)
        result_str += code_map[c];

    std::cout << code_map.size() << " " << result_str.size() << std::endl;

    for (const auto& i : code_map)
        std::cout << i.first << ": " << i.second << std::endl;

    std::cout << result_str << std::endl;

    return 0;
}
