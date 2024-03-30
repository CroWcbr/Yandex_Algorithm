/*
E. Нумерация дробей
Георг Кантор доказал, что множество всех рациональных чисел счетно (т.е. все рациональные числа можно пронумеровать).
Чтобы упорядочить дроби необходимо их положить в таблицу, как показано на рисунке. В строку с номером i этой матрицы по порядку записаны дроби с числителем i, а в столбец с номером j дроби с знаменателем j.
Дальше необходимо выписать все дроби в том порядке, как показано на рисунке стрелками. Получится такая последовательность: 1/1, 2/1, 1/2, 1/3, 2/2, 3/1, …
Вам требуется по числу n найти числитель и знаменатель n-ой дроби.

Формат ввода
Во входном файле дано число n (1 ≤ n ≤ 10^18) — порядковый номер дроби в последовательности.

Формат вывода
В выходной файл требуется вывести через символ / два числа: числитель и знаменатель соответствующей дроби.
*/

#include <iostream>
#include <vector>
#include <cmath>

size_t binary_search(size_t n)
{
    size_t left = 1;
    size_t right = n;

    while (left < right)
    {
        size_t mid = (left + right) / 2;
        // std::cout << left << " " << right << " " << mid << std::endl;
        if (mid >= std::sqrt(2 * n)) // mid * mid can be too big
            right = mid;
        else
        {
            if (mid * (mid + 1) >= 2 * n)
                right = mid;
            else
                left = mid + 1;
        }
        // std::cout << "\t"  << left << " " << right << std::endl;
    }
    return left;
}

int main()
{
    size_t n;
    std::cin >> n;

    size_t diagonal = binary_search(n);

    size_t count = diagonal * (diagonal + 1) / 2;
    size_t pos = count - n;
    size_t numerator, denominator;

    // std::cout << count << "\t" << diagonal << "\t" << pos << std::endl;
    numerator = diagonal - pos;
    denominator = 1 + pos;

    if (diagonal % 2 == 0)
        std::swap(numerator, denominator);

    std::cout << numerator << "/" << denominator << std::endl;
    return 0;
}