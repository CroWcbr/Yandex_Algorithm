/*
C. Удаление чисел
Дан массив a из n чисел. Найдите минимальное количество чисел, после удаления которых попарная разность оставшихся чисел по модулю не будет превышать 1, то есть после удаления ни одно число не должно отличаться от какого-либо другого более чем на 1.

Формат ввода
Первая строка содержит одно целое число n (1≤n≤2⋅10^5) — количество элементов массива a.
Вторая строка содержит n целых чисел a1,a2,…,an (0≤ai≤10^5) — элементы массива a.

Формат вывода
Выведите одно число — ответ на задачу.
*/

#include <iostream>
#include <map>

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
