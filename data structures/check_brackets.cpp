#include "log_duration.h"

#include <iostream>
#include <stack>
#include <deque>
#include <string>
#include <cassert>

// https://stepik.org/lesson/41234/step/1

namespace
{
    char open_bracket(char close_bracket)
    {
        switch (close_bracket)
        {
            case ')': return '(';
            case ']': return '[';
            case '}': return '{';

            default : return '-';
        }
    }
}

int check_brackets(std::string_view str)
{
    std::stack<char> stack;
    std::deque<int> brackets_pos;

    for (size_t i = 0, s = str.size(); i < s; ++i)
    {
        char c = str[i];

        switch (c)
        {
            case '(':
            case '[':
            case '{':
            {
                stack.push(c);
                brackets_pos.push_back(static_cast<int>(i));
            }
            break;

            case ')':
            case ']':
            case '}':
            {
                if (!stack.empty() && open_bracket(c) == stack.top())
                {
                    stack.pop();
                    brackets_pos.pop_back();
                }
                else
                    return static_cast<int>(i);
            }
            break;

            default: break;
        }
    }

    return brackets_pos.empty() ? -1 : brackets_pos.front();
}

void test()
{
    assert(check_brackets("[]") == -1);
    assert(check_brackets("{}[]") == -1);
    assert(check_brackets("[()]") == -1);
    assert(check_brackets("(())") == -1);
    assert(check_brackets("{[]}()") == -1);
    assert(check_brackets("foo(bar);") == -1);
    assert(check_brackets("([](){([])})") == -1);

    assert(check_brackets("{") == 0);
    assert(check_brackets("{[}") == 2);
    assert(check_brackets("foo(bar[i);") == 9);
    assert(check_brackets("(([]") == 0);
    assert(check_brackets("()[]}") == 4);
    assert(check_brackets("{{[()]]") == 6);
}

int main()
{
    std::string str;

    std::cin >> str;

    int error_pos = check_brackets(str);

    if (error_pos == -1)
        std::cout << "Success";
    else
        std::cout << error_pos + 1;

    std::cout << '\n';

    return 0;
}
