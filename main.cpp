#include "log_duration.h"

#include <iostream>
#include <cassert>
#include <utility>
#include <vector>
#include <algorithm>
#include <ios>
#include <map>
#include <unordered_map>
#include <set>
#include <string>

// gcd ------------------------------------------------------------------------------------------------------------------------------------

//template <class Int>
//Int gcd(Int a, Int b)
//{
//    while (a > 0 && b > 0)
//    {
//        if (a > b)
//            a %= b;
//        else
//            b %= a;
//    }

//    return a == 0 ? b : a;
//}

// covering set ------------------------------------------------------------------------------------------------------------------------------------

//std::vector<int> get_covering_set(std::vector<std::pair<int, int>>&& segments)
//{
//    assert(segments.size() > 0);

//    std::vector<int> result;

//    std::sort(segments.begin(), segments.end(), [](const std::pair<int, int>& l, const std::pair<int, int>& r)
//              {
//                  return l.second < r.second;
//              });

//    result.push_back(segments.front().second);

//    for (auto s : segments)
//    {
//        if (result.back() >= s.first)
//            continue;
//        else
//            result.push_back(s.second);
//    }

//    return result;
//}

//int main()
//{
//    int segments_count;
//    std::cin >> segments_count;

//    std::vector <std::pair<int, int>> segments(segments_count);

//    for (auto& s : segments)
//    {
//        std::cin >> s.first >> s.second;
//    }

//    std::vector<int> points = get_covering_set(std::move(segments));

//    std::cout << points.size() << std::endl;

//    for (int point : points)
//    {
//        std::cout << point << " ";
//    }

//    std::cout << std::endl;

//    return 0;
//}

// max knapsack value ------------------------------------------------------------------------------------------------------------------------------------

//struct Item
//{
//    int weight;
//    int value;
//};

//double get_max_knapsack_value(int capacity, std::vector<Item>&& items)
//{
//    double result = 0.0;

//    std::sort(items.begin(), items.end(), [](const Item& l, const Item& r)
//              {
//                  return l.value * 1. / l.weight > r.value * 1. / r.weight; // можно заменить умножением для увеличения быстродействия
//              });

//    for (auto& item : items)
//    {
//        if (capacity > item.weight)
//        {
//            capacity -= item.weight;
//            result += item.value;
//        }
//        else
//        {
//            result += item.value * (static_cast <double>(capacity) / item.weight);
//            break;
//        }
//    }

//    return result;
//}

//int main()
//{
//    std::ios_base::sync_with_stdio(false);

//    int number_of_items;
//    int knapsack_capacity;

//    std::cin >> number_of_items >> knapsack_capacity;

//    std::vector<Item> items(number_of_items);

//    for (int i = 0; i < number_of_items; i++)
//        std::cin >> items[i].value >> items[i].weight;

//    double max_knapsack_value = get_max_knapsack_value(knapsack_capacity, std::move(items));

//    std::cout.precision(10);
//    std::cout << max_knapsack_value << std::endl;

//    return 0;
//}

// max different components of a number ------------------------------------------------------------------------------------------------------------------------------------

//std::vector<int> get_max_different_components(int n)
//{
//    std::vector<int> result;

//    int sum = 0;

//    for (int i = 1; n > i * 2; ++i)
//    {
//        result.push_back(i);

//        sum += i;

//        n -= i;
//    }

//    result.push_back(n);

//    return result;
//}

//int main()
//{
//    int n;
//    std::cin >> n;

//    std::vector<int> components = get_max_different_components(n);

//    std::cout << components.size() << std::endl;

//    for (int i : components)
//        std::cout << i << " ";

//    std::cout << std::endl;

//    return 0;
//}

// Huffman code (looks terrible) ------------------------------------------------------------------------------------------------------------------------------------

//void make_node(std::set<std::pair<int, std::string>>& heap, std::unordered_map<char, std::string>& code_map)
//{
//    assert(heap.size() > 1);

//    auto min_1 = heap.begin();

//    for (char c : min_1->second)
//        code_map[c].insert(0, "0");

//    auto min_2 = std::next(heap.begin());

//    for (char c : min_2->second)
//        code_map[c].insert(0, "1");

//    std::pair<int, std::string> new_node{min_1->first + min_2->first, min_1->second + min_2->second};

//    heap.erase(min_1);
//    heap.erase(min_2);

//    heap.insert(std::move(new_node));
//}

//int main()
//{
//    std::string s;
//    std::cin >> s;

//    std::unordered_map<char, int> freqs;

//    for (char c : s)
//    {
//        if (freqs.find(c) == freqs.end())
//            freqs[c] = 1;
//        else
//            ++freqs[c];
//    }

//    std::set<std::pair<int, std::string>> freqsSet;

//    for (auto i = freqs.begin(); i != freqs.end(); ++i)
//    {
//        freqsSet.emplace(std::pair<int, std::string>(i->second, std::string{i->first}));
//    }

//    std::unordered_map<char, std::string> code_map;

//    if (freqs.size() == 1)
//        code_map[s[0]] = "0";

//    while (freqsSet.size() > 1)
//        make_node(freqsSet, code_map);

//    std::string result_str;

//    for (char c : s)
//        result_str += code_map[c];

//    std::cout << code_map.size() << " " << result_str.size() << std::endl;

//    for (const auto& i : code_map)
//        std::cout << i.first << ": " << i.second << std::endl;

//    std::cout << result_str << std::endl;

//    return 0;
//}

// Huffman decode (looks terrible) ------------------------------------------------------------------------------------------------------------------------------------

//std::string huffman_decode(const std::string& encoded_str, const std::unordered_map<std::string, char>& codes)
//{
//    std::string result;

//    std::string buf;

//    for (char c : encoded_str)
//    {
//        buf.push_back(c);

//        auto code_it = codes.find(buf);

//        if (code_it != codes.end())
//        {
//            result += code_it->second;
//            buf.clear();
//        }
//    }

//    return result;
//}

//int main()
//{
//    int letters_count;
//    int str_size;

//    std::cin >> letters_count >> str_size;

//    std::unordered_map<std::string, char> letter_codes;

//    for (int i = 0; i < letters_count; ++i)
//    {
//        char letter;
//        char delimeter;
//        std::string code;

//        std::cin >> letter >> delimeter >> code;

//        letter_codes[code] = letter;
//    }

//    std::string encoded_str;
//    std::cin >> encoded_str;

//    std::cout << huffman_decode(encoded_str, letter_codes) << std::endl;

//    return 0;
//}

// Priority queue ------------------------------------------------------------------------------------------------------------------------------------

//class PriorityQueue
//{
//public:
//    explicit PriorityQueue()
//    {}

//public:
//    void insert(int value)
//    {
//        m_queue.push_back(value);
//        siftUp(static_cast<int>(m_queue.size()) - 1);
//    }

//    int extractMax()
//    {
//        int maxValue = m_queue[0];

//        std::swap(m_queue[0], m_queue[m_queue.size() - 1]);

//        m_queue.pop_back();

//        siftDown(0);

//        return maxValue;
//    }

//private:
//    void siftUp(int i)
//    {
//        while (true)
//        {
//            int parentInd = parentIndex(i);

//            if (parentInd == -1 || m_queue[i] <= m_queue[parentInd])
//                break;

//            std::swap(m_queue[i], m_queue[parentInd]);

//            i = parentInd;
//        }
//    }

//    void siftDown(int i)
//    {
//        while (true)
//        {
//            std::vector<int> children = childrenIndexes(i);

//            if (children.empty())
//                break;

//            int maxChildIndex = *std::max_element(children.begin(), children.end(), [this](int l, int r)
//                                                  {
//                                                      return m_queue[l] < m_queue[r];
//                                                  });

//            if (m_queue[i] > m_queue[maxChildIndex])
//                break;

//            std::swap(m_queue[maxChildIndex], m_queue[i]);

//            i = maxChildIndex;
//        }
//    }

//    int parentIndex(int i)
//    {
//        return i == 0 ? -1 : (i - 1) / 2;
//    }

//    std::vector<int> childrenIndexes(int i)
//    {
//        std::vector<int> result;

//        int firstChild  = i * 2 + 1;
//        int secondChild = i * 2 + 2;

//        if (firstChild < m_queue.size())
//            result.push_back(firstChild);

//        if (secondChild < m_queue.size())
//            result.push_back(secondChild);

//        return result;
//    }

//private:
//    std::vector<int> m_queue;
//};

//int main()
//{
//    int n;
//    std::cin >> n;

//    PriorityQueue priorityQueue;

//    for (int i = 0; i < n; ++i)
//    {
//        std::string cmd;
//        int value;

//        std::cin >> cmd;

//        if (cmd == "Insert")
//        {
//            std::cin >> value;

//            priorityQueue.insert(value);
//        }
//        else if (cmd == "ExtractMax")
//            std::cout << priorityQueue.extractMax() << std::endl;
//    }

//    return 0;
//}
