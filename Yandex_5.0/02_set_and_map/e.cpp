/*
E. Два из трех
Вам даны три списка чисел. Найдите все числа, которые встречаются хотя бы в двух из трёх списков.

Формат ввода
Во входных данных описывается три списка чисел. Первая строка каждого описания списка состоит из длины списка n (1 ≤ n ≤ 1000). Вторая строка описания содержит список натуральных чисел, записанных через пробел. Числа не превосходят 10^9.

Формат вывода
Выведите все числа, которые содержатся хотя бы в двух списках из трёх, в порядке возрастания. Обратите внимание, что каждое число необходимо выводить только один раз.
*/

#include <iostream>
#include <set>
#include <map>

int main()
{
    std::map<int, int> ans;
    for (int i3 = 0; i3 < 3; i3++)
    {
        int n;
        std::cin >> n;

        std::set<int> tmp;
        for (int i = 0; i < n; i++)
        {
            int x;
            std::cin >> x;
            tmp.insert(x);
        }
        for (auto i : tmp)
            ans[i]++;
    }

    for (auto i : ans)
        if (i.second > 1)
            std::cout << i.first << " ";
    std::cout << std::endl;
    return 0;
}