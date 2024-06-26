/*
C. Петя, Маша и верёвочки
На столе лежали две одинаковые верёвочки целой положительной длины.
Петя разрезал одну из верёвочек на N частей, каждая из которых имеет целую положительную длину, так что на столе стало N+1 верёвочек. Затем в комнату зашла Маша и взяла одну из лежащих на столе верёвочек. По длинам оставшихся на столе N верёвочек определите, какую наименьшую длину может иметь верёвочка, взятая Машей.

Формат ввода
Первая строка входных данных содержит одно целое число N — количество верёвочек, оставшихся на столе (2 ≤ N ≤ 1000). Во второй строке содержится N целых чисел li — длины верёвочек (1 ≤ li ≤ 1000).

Формат вывода
Выведите одно целое число — наименьшую длину, которую может иметь верёвочка, взятая Машей.
*/

#include <iostream>

int main()
{
	int N;
    std::cin >> N;

    int l;
    std::cin >> l;
    int max, tmp;
    max = tmp = l;
    for (int i = 1; i < N; ++i)
    {
        std::cin >> l;
        tmp += l;
        if (l > max)
            max = l;
    }

    int answer = max + max - tmp;
    std::cout << (answer <= 0 ? tmp : answer) << std::endl;
    return 0;
}