#include "log_duration.h"

#include <iostream>
#include <unordered_map>
#include <string>

// https://stepik.org/lesson/13239/step/6

std::string huffman_decode(const std::string& encoded_str, const std::unordered_map<std::string, char>& codes)
{
    std::string result;

    std::string buf;

    for (char c : encoded_str)
    {
        buf.push_back(c);

        auto code_it = codes.find(buf);

        if (code_it != codes.end())
        {
            result += code_it->second;
            buf.clear();
        }
    }

    return result;
}

int main()
{
    int letters_count;
    int str_size;

    std::cin >> letters_count >> str_size;

    std::unordered_map<std::string, char> letter_codes;

    for (int i = 0; i < letters_count; ++i)
    {
        char letter;
        char delimeter;
        std::string code;

        std::cin >> letter >> delimeter >> code;

        letter_codes[code] = letter;
    }

    std::string encoded_str;
    std::cin >> encoded_str;

    std::cout << huffman_decode(encoded_str, letter_codes) << std::endl;

    return 0;
}
