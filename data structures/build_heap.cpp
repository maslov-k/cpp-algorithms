#include "log_duration.h"

#include <iostream>
#include <vector>

// https://stepik.org/lesson/41560/step/1

struct Change
{
    size_t index_1;
    size_t index_2;
};

template<typename T>
class HeapMin
{
public:
    HeapMin()
    {}

    HeapMin(std::vector<T>&& data)
        : _data(data)
    {
        fix_heap();
    }

    const std::vector<Change> changes()
    {
        return _changes;
    }

    size_t size()
    {
        return _data.size();
    }

    void insert(const T& p)
    {
        _data.push_back(p);
        sift_up(_data.size() - 1);
    }

    T extract_max()
    {
        T result(std::move(_data.front()));

        std::swap(_data.front(), _data.back());

        _data.pop_back();

        sift_down(0);

        return result;
    }

    void remove(size_t i)
    {
        std::swap(_data[i], _data.back());

        _data.pop_back();

        sift_down(i);
    }

    const T& operator[](size_t i)
    {
        return _data[i];
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

    T& parent(size_t i)
    {
        return _data[parent_index(i)];
    }

    T& left_child(size_t i)
    {
        return _data[left_child_index(i)];
    }

    T& right_child(size_t i)
    {
        return _data[right_child_index(i)];
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
        while (i > 0 && parent(i) > _data[i])
        {
            std::swap(parent(i), _data[i]);
            i = parent_index(i);
        }
    }

    void sift_down(size_t i)
    {
        size_t min_index = i;

        if (has_left_child(i) && left_child(i) < _data[min_index])
            min_index = left_child_index(i);

        if (has_right_child(i) && right_child(i) < _data[min_index])
            min_index = right_child_index(i);

        if (i != min_index)
        {
            std::swap(_data[i], _data[min_index]);

            _changes.push_back({i, min_index});

            sift_down(min_index);
        }
    }

    void fix_heap()
    {
        _changes.clear();

        for (int i = static_cast<int>(size() / 2 - 1); i >= 0; --i)
            sift_down(i);
    }

private:
    std::vector<T> _data;

    std::vector<Change> _changes;
};

int main()
{
    int n;

    std::cin >> n;

    std::vector<int> a;
    a.reserve(n);

    for (int i = 0; i < n; ++i)
    {
        int v;
        std::cin >> v;

        a.push_back(v);
    }

    HeapMin<int> heap(std::move(a));

    const std::vector<Change> changes = heap.changes();

    std::cout << changes.size() << '\n';

    for (Change change : changes)
        std::cout << change.index_1 << ' ' << change.index_2 << '\n';

    std::cout << '\n';

    return 0;
}
