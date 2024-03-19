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