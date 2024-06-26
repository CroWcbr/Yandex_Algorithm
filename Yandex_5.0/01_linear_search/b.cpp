/*
B. Продавец рыбы
Вася решил заняться торговлей рыбой. С помощью методов машинного обучения он предсказал цены на рыбу на N дней вперёд. Он решил, что в один день он купит рыбу, а в один из следующих дней — продаст (то есть совершит или ровно одну покупку и продажу или вообще не совершит покупок и продаж, если это не принесёт ему прибыли). К сожалению, рыба — товар скоропортящийся и разница между номером дня продажи и номером дня покупки не должна превышать K.
Определите, какую максимальную прибыль получит Вася.

Формат ввода
В первой строке входных данных задаются числа N и K (1 ≤ N ≤ 10000, 1 ≤ K ≤ 100).

Во второй строке задаются цены на рыбу в каждый из N дней. Цена — целое число, которое может находится в пределах от 1 до 10^9.

Формат вывода
Выведите одно число — максимальную прибыль, которую получит Вася.
*/

#include <iostream>
#include <vector>

int main()
{
	int N, K;
	std::cin >> N >> K;

    int prev, next;
    std::cin >> prev;
    int min_next = -1;
    int left_next = -1;

    int answer = 0;
    int left = 0;
    int min = prev;
    for (int i = 1; i < N; ++i)
    {
        std::cin >> next;
        if (min >= next)
        {
            min = next;
            left = i;
            min_next = -1;
            left_next = -1;
            continue;
        }

        if (min_next == -1 || min_next >= next)
        {
            min_next = next;
            left_next = i;
        }

        if (i - left > K)
        {
            left = left_next;
            min = min_next;
            min_next = -1;
            left_next = -1;
        }

        if (answer < next - min)
            answer = next - min;
    }
    std::cout << answer << std::endl;
    return 0;
}