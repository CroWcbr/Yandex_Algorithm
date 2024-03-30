/*
F. Замена слов
С целью экономии чернил в картридже принтера было принято решение укоротить некоторые слова в тексте. Для этого был составлен словарь слов, до которых можно сокращать более длинные слова. Слово из текста можно сократить, если в словаре найдется слово, являющееся началом слова из текста. Например, если в списке есть слово "лом", то слова из текста "ломбард", "ломоносов" и другие слова, начинающиеся на "лом", можно сократить до "лом".
Если слово из текста можно сократить до нескольких слов из словаря, то следует сокращать его до самого короткого слова.

Формат ввода
В первой строке через пробел вводятся слова из словаря, слова состоят из маленьких латинских букв. Гарантируется, что словарь не пуст и количество слов в словаре не превышет 1000, а длина слов — 100 символов.
Во второй строке через пробел вводятся слова текста (они также состоят только из маленьких латинских букв). Количество слов в тексте не превосходит 10^5, а суммарное количество букв в них — 10^6.

Формат вывода
Выведите текст, в котором осуществлены замены.
*/

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