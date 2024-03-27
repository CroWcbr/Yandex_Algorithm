#include <iostream>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <string>

int main()
{
    std::string input_string;
    std::getline(std::cin, input_string);

    std::unordered_map<char, std::unordered_set<std::string>> words;
    std::string new_word;
    
    std::istringstream iss(input_string);
    while (iss >> new_word)
    {
        bool tmp = true;
        auto& words_char = words[new_word[0]];
        for (auto it = words_char.begin(); it != words_char.end();)
        {
            const std::string& word = *it;
            if (new_word.compare(0, word.length(), word) == 0)
            {
                tmp = false;
                break;
            }
            if (word.compare(0, new_word.length(), new_word) == 0)
                it = words_char.erase(it);
            else
                ++it;
        }
        if (tmp)
            words_char.insert(new_word);
    }

    std::getline(std::cin, input_string);
    std::istringstream iss2(input_string);
    while (iss2 >> new_word)
    {
        bool tmp = true;
        auto& words_char = words[new_word[0]];
        for (const auto& word : words_char)
        {
            if (new_word.compare(0, word.length(), word) == 0)
            {
                std::cout << word << " ";
                tmp = false;
            }
        }
        if (tmp)
            std::cout << new_word << " ";
    }
    std::cout << std::endl;

    return 0;
}