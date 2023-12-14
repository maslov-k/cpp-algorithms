#include "log_duration.h"

#include <iostream>
#include <vector>
#include <algorithm>

// https://stepik.org/lesson/13240/step/8

class PriorityQueue
{
public:
    explicit PriorityQueue()
    {}

public:
    void Insert(int value)
    {
        m_queue.push_back(value);
        SiftUp(static_cast<int>(m_queue.size()) - 1);
    }

    int ExtractMax()
    {
        int maxValue = m_queue[0];

        std::swap(m_queue[0], m_queue[m_queue.size() - 1]);

        m_queue.pop_back();

        SiftDown(0);

        return maxValue;
    }

private:
    void SiftUp(int i)
    {
        while (true)
        {
            int parentInd = ParentIndex(i);

            if (parentInd == -1 || m_queue[i] <= m_queue[parentInd])
                break;

            std::swap(m_queue[i], m_queue[parentInd]);

            i = parentInd;
        }
    }

    void SiftDown(int i)
    {
        while (true)
        {
            std::vector<int> children = ChildrenIndexes(i);

            if (children.empty())
                break;

            int maxChildIndex = *std::max_element(children.begin(), children.end(), [this](int l, int r)
                                                  {
                                                      return m_queue[l] < m_queue[r];
                                                  });

            if (m_queue[i] > m_queue[maxChildIndex])
                break;

            std::swap(m_queue[maxChildIndex], m_queue[i]);

            i = maxChildIndex;
        }
    }

    int ParentIndex(int i)
    {
        return i == 0 ? -1 : (i - 1) / 2;
    }

    std::vector<int> ChildrenIndexes(int i)
    {
        std::vector<int> result;

        int first_child  = i * 2 + 1;
        int second_child = i * 2 + 2;

        if (first_child < m_queue.size())
            result.push_back(first_child);

        if (second_child < m_queue.size())
            result.push_back(second_child);

        return result;
    }

private:
    std::vector<int> m_queue;
};

int main()
{
    int n;
    std::cin >> n;

    PriorityQueue priority_queue;

    for (int i = 0; i < n; ++i)
    {
        std::string cmd;
        int value;

        std::cin >> cmd;

        if (cmd == "Insert")
        {
            std::cin >> value;

            priority_queue.Insert(value);
        }
        else if (cmd == "ExtractMax")
            std::cout << priority_queue.ExtractMax() << std::endl;
    }

    return 0;
}
