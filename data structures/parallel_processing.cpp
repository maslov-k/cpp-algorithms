#include "log_duration.h"

#include <iostream>
#include <vector>

// https://stepik.org/lesson/41560/step/2

template<typename T>
struct Element
{
    T   data;
    int64_t priority;

    bool operator < (const Element<T>& other) const
    {
        return priority == other.priority ? data < other.data : priority < other.priority;
    }
};



template<typename T>
class HeapMin
{
public:
    HeapMin()
    {}

    HeapMin(std::vector<Element<T>>&& data)
        : _elements(data)
    {}

    void fix_heap()
    {
        for (int i = static_cast<int>(size() / 2 - 1); i >= 0; --i)
            sift_down(i);
    }

    size_t size()
    {
        return _elements.size();
    }

    void insert(const Element<T>& el)
    {
        _elements.push_back(el);
        sift_up(_elements.size() - 1);
    }

    Element<T> extract_min()
    {
        Element<T> result(std::move(_elements.front()));

        std::swap(_elements.front(), _elements.back());

        _elements.pop_back();

        sift_down(0);

        return result;
    }

    void change_priority(size_t i, int64_t p)
    {
        int64_t old_p = _elements[i].priority;

        _elements[i].priority = p;

        if (p < old_p)
            sift_up(i);
        else
            sift_down(i);
    }

    void remove(size_t i)
    {
        std::swap(_elements[i], _elements.back());

        _elements.pop_back();

        sift_down(i);
    }

    const Element<T>& top()
    {
        return _elements[0];
    }

    const Element<T>& operator[](size_t i)
    {
        return _elements[i];
    }

private:
    size_t parent_index(size_t i)
    {
        return (i - 1) / 2;
    }

    size_t left_child_index(size_t i)
    {
        return 2 * i + 1;
    }

    size_t right_child_index(size_t i)
    {
        return 2 * i + 2;
    }

    Element<T>& parent(size_t i)
    {
        return _elements[parent_index(i)];
    }

    Element<T>& left_child(size_t i)
    {
        return _elements[left_child_index(i)];
    }

    Element<T>& right_child(size_t i)
    {
        return _elements[right_child_index(i)];
    }

    bool has_parent(size_t i)
    {
        return (i > 0);
    }

    bool has_left_child(size_t i)
    {
        return (left_child_index(i) < size());
    }

    bool has_right_child(size_t i)
    {
        return (right_child_index(i) < size());
    }

    void sift_up(size_t i)
    {
        while (i > 0 && _elements[i] < parent(i))
        {
            std::swap(parent(i), _elements[i]);
            i = parent_index(i);
        }
    }

    void sift_down(size_t i)
    {
        size_t min_index = i;

        if (has_left_child(i) && left_child(i) < _elements[min_index])
            min_index = left_child_index(i);

        if (has_right_child(i) && right_child(i) < _elements[min_index])
            min_index = right_child_index(i);

        if (i != min_index)
        {
            std::swap(_elements[i], _elements[min_index]);

            sift_down(min_index);
        }
    }

private:
    std::vector<Element<T>> _elements;
};

int main()
{
    int n;
    int m;

    std::cin >> n;
    std::cin >> m;

    std::vector<int64_t> tasks;
    tasks.reserve(m);

    for (int i = 0; i < m; ++i)
    {
        int64_t time;
        std::cin >> time;

        tasks.push_back(time);
    }

    std::vector<Element<int>> processors;
    processors.reserve(n);

    for (int i = 0; i < n; ++i)
        processors.push_back({i, 0});

    HeapMin<int> heap(std::move(processors));

    for (int64_t task_time : tasks)
    {
        const Element<int>& processor = heap.top();

        std::cout << processor.data << ' ' << processor.priority << '\n';

        heap.change_priority(0, processor.priority + task_time);
    }

    return 0;
}
