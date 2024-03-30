/*
G. Ни больше ни меньше
Дан массив целых положительных чисел a длины n. Разбейте его на минимально возможное количество отрезков, чтобы каждое число было не меньше длины отрезка которому оно принадлежит. Длиной отрезка считается количество чисел в нем.
Разбиение массива на отрезки считается корректным, если каждый элемент принадлежит ровно одному отрезку.

Формат ввода
Первая строка содержит одно целое число t (1 ≤ t ≤ 1000) — количество наборов тестовых данных. Затем следуют t наборов тестовых данных.
Первая строка набора тестовых данных содержит одно целое число n (1 ≤ n ≤ 10^5) — длину массива.
Следующая строка содержит n целых чисел a1, a2, …, an (1 ≤ ai ≤ n) — массив a.
Гарантируется, что сумма n по всем наборам тестовых данных не превосходит 2 ⋅ 10^5.

Формат вывода
Для каждого набора тестовых данных в первой строке выведите число k — количество отрезков в вашем разбиении.
Затем в следующей строке выведите k чисел len1, len2, …, lenk (1 ≤ leni ≤ n,) — длины отрезков в порядке слева направо.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i)
    {
        int n;
        std::cin >> n;

        std::vector<int> data(n);
        for (int a = 0; a < n; ++a)
            std::cin >> data[a];
        // sort(data.begin(), data.end());

        std::vector<int> answer;
        std::vector<int> tmp;
        int min = -1;
        for (int a = 0; a < n; ++a)
        {
            if (min == -1 || min > data[a])
            {
                min = data[a];
                if (min < tmp.size() + 1)
                {
                    answer.push_back(tmp.size());
                    tmp.clear();  
                }
            }

            tmp.push_back(data[a]);
            // std::cout << a << "\t" << data[a] << "\t" << tmp.back() << "\t" << tmp.size() << std::endl;
            if (min == tmp.size() || a == n - 1)
            {
                answer.push_back(tmp.size());
                tmp.clear();
                min = -1;
            }
        }
        std::cout << answer.size() << std::endl;
        for (int a = 0; a < answer.size(); ++a)
            std:: cout << answer[a] << " ";
        std::cout << std::endl;
    }

    return 0;
}
