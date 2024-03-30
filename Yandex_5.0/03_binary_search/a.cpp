/*
A. Быстрый поиск в массиве
Дан массив из N целых чисел. Все числа от −10^9 до 10^9.
Нужно уметь отвечать на запросы вида “Cколько чисел имеют значения от L до R?”.

Формат ввода
Число N (1≤N≤10^5). Далее N целых чисел.
Затем число запросов K (1≤K≤10^5).
Далее K пар чисел L,R (−10^9≤L≤R≤10^9) — собственно запросы.

Формат вывода
Выведите K чисел — ответы на запросы.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int binary_search(const std::vector<int>& data, int value, bool upper)
{
    int left = 0;
    int right = data.size();

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (data[mid] < value + upper)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int main()
{
    int N;
    std::cin >> N;

    std::vector<int> data(N);
    for (int i = 0; i < N; ++i)
        std::cin >> data[i];
    
    std::sort(data.begin(), data.end());

    int K;
    std::cin >> K;
    for (int i = 0; i < K; ++i)
    {
        int L, R;
        std::cin >> L >> R;

        // auto lower = std::lower_bound(data.begin(), data.end(), L);
        // auto upper = std::upper_bound(data.begin(), data.end(), R);
        int lower = binary_search(data, L, false);
        int upper = binary_search(data, R, true);
        std::cout << upper - lower << " ";

    }
    std::cout << std::endl;
    return 0;
}