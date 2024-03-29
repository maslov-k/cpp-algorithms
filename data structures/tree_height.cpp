#include "log_duration.h"

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

// https://stepik.org/lesson/41234/step/2

std::unordered_map<int, std::vector<int>> build_tree(const std::vector<int>& vec)
{
    std::unordered_map<int, std::vector<int>> result;

    for (int i = 0, c = vec.size(); i < c; ++i)
        result[vec[i]].push_back(i);

    return result;
}

int tree_height(const std::unordered_map<int, std::vector<int>>& tree, int root_index)
{
    if (tree.count(root_index) == 0)
        return 1;

    int height = 1;

    const std::vector<int>& children = tree.at(root_index);

    for (int child : children)
        height = std::max(height, tree_height(tree, child) + 1);

    return height;
}

void test()
{
    assert(tree_height(build_tree({9, 7, 5, 5, 2, 9, 9, 9, 2, -1}), 9) == 4);
    assert(tree_height(build_tree({4, -1, 4, 1, 1}), 1) == 3);
    assert(tree_height(build_tree({-1, 0, 4, 0, 3}), 0) == 4);
}

int main()
{
    int n;

    std::cin >> n;

    std::vector<int> vector_tree;
    vector_tree.reserve(n);

    for (int i = 0; i < n; ++i)
    {
        int v;
        std::cin >> v;

        vector_tree.push_back(v);
    }

    std::unordered_map<int, std::vector<int>> tree = build_tree(vector_tree);

    std::cout << tree_height(tree, tree[-1].front()) << '\n';

    return 0;
}
