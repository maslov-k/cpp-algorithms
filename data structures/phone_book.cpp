#include "log_duration.h"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// https://stepik.org/lesson/41562/step/1

class PhoneBook
{
public:
    PhoneBook()
        : _numbers(10000000, "")
    {}

    void add(int number, std::string_view name)
    {
        _numbers[number] = name;
    }

    std::string_view find(int number)
    {
        return _numbers[number];
    }

    void del(int number)
    {
        _numbers[number].clear();
    }

private:
    std::vector<std::string> _numbers;
};

int main()
{
    int n;

    std::cin >> n;

    PhoneBook phone_book;

    for (int i = 0; i < n; ++i)
    {
        std::string cmd;

        std::cin >> cmd;

        if (cmd == "add")
        {
            int         number;
            std::string name;

            std::cin >> number;
            std::cin >> name;

            phone_book.add(number, name);
        }
        else if (cmd == "find")
        {
            int number;

            std::cin >> number;

            std::string_view name = phone_book.find(number);

            std::cout << (name.empty() ? "not found" : name) << '\n';
        }
        else if (cmd == "del")
        {
            int number;

            std::cin >> number;

            phone_book.del(number);
        }
    }

    return 0;
}
