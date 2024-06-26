/*
B. Анаграмма?
Задано две строки, нужно проверить, является ли одна анаграммой другой. Анаграммой называется строка, полученная из другой перестановкой букв.

Формат ввода
Строки состоят из строчных латинских букв, их длина не превосходит 100000. Каждая записана в отдельной строке.

Формат вывода
Выведите "YES" если одна из строк является анаграммой другой и "NO" в противном случае.
*/

#include <iostream>
#include <string>
#include <map>


int main()
{
    std::string s1, s2;
    std::cin >> s1 >> s2;

    std::map<char, int> d1, d2;
    for (char c = 'a'; c <= 'z'; ++c)
    {
        d1[c] = d2[c] = 0;
    }

    for (auto& c : s1)
        d1[c]++;

    for (auto& c : s2)
        d2[c]++;

    std::cout << (d1 == d2 ? "YES" : "NO") << std::endl;
    return 0;
}