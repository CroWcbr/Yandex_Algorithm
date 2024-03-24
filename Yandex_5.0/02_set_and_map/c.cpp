#include <iostream>
# include <map>

int main()
{
    int n;
    std::cin >> n;

    std::map<int, int> data;
    for (int i = 0; i < n; ++i)
    {
        int a;
        std::cin >> a;
        data[a] += 1;
    }

    auto it1 = data.begin();
    auto it2 = std::next(it1);
    int answer = 0;
    int max = it1->second;
    for (; it2 != data.end(); ++it1, ++it2)
    {
        if (it2->first - it1->first == 1 && answer < it2->second + it1->second)
            answer = it2->second + it1->second;
        if (max < it2->second)
            max = it2->second;
    }

    std::cout << (answer ? n - answer : n - max) << std::endl;
    return 0;
}
