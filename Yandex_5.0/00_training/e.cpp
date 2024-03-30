/*
E. Прибыльный стартап
k друзей организовали стартап по производству укулеле для кошек. На сегодняшний день прибыль составила n рублей. Вы, как главный бухгалтер компании, хотите в каждый из ближайших d дней приписывать по одной цифре в конец числа, выражающего прибыль. При этом в каждый из дней прибыль должна делиться на k.

Формат ввода
В единственной строке входных данных через пробел записаны три числа: n, k, d — изначальная прибыль, количество учредителей компании и количество дней, которое вы собираетесь следить за прибылью (1≤n,k≤10^9,1≤d≤10^5). НЕ гарантируется, что n делится на k.

Формат вывода
Выведите одно целое число x — прибыль компании через d дней. Первые цифры числа x должны совпадать с числом n. Все префиксы числа x, которые длиннее числа n на 1,2,…,d цифр, должны делиться на k. Если возможных ответов несколько, выведите любой из них. Если ответа не существует, выведите −1.
*/
#include <iostream>
#include <vector>
#include <string>

bool isValueInVector(const std::vector<long long int>& vec, int value)
{
    for (const auto& element : vec)
        if (element == value)
            return true;
    return false;
}

int main()
{
    int n, k, d;
    std::cin >> n >> k >> d;

    std::vector<long long int> reminder(1, n % k);
    std::vector<std::string> answer(1, std::to_string(n));
    for (int i = 0; i < d; ++i)
    {
        std::vector<long long int> update_reminder;
        std::vector<std::string> update_answer;
        for (int v = 0; v < reminder.size(); ++v)
            for (int j = 0; j < 10; ++j)
            {
                int tmp = (reminder[v] * 10 + j) % k;
                if (tmp == 0 && !isValueInVector(update_reminder, tmp))
                {
                    update_reminder.push_back(tmp);
                    update_answer.push_back(answer[v] + std::to_string(j));
                }
            }
        reminder = std::move(update_reminder);
        answer = std::move(update_answer);
    }
    if (reminder.empty())
        std::cout << -1 << std::endl;
    else
        std::cout << answer[0] << std::endl;
    return 0;
}