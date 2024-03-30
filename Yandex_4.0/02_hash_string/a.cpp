/*
A. Равенство подстрок
Дана строка S, состоящая из строчных латинских букв.
Определите, совпадают ли строки одинаковой длины L, начинающиеся с позиций A и B.

Формат ввода
В первой строке записана S (1 ≤ |S| ≤ 2 ⋅ 10^5), состоящая из строчных латинских букв.
Во второй строке записано число Q (1 ≤ Q ≤ 2 ⋅ 10^5) — количество запросов.
В следющих Q строках записаны запросы: целые числа L, A и B (1 ≤ L ≤ |S|, 0 ≤ A, B ≤ (|S| - L)) — длина подстрок и позиции, с которых они начинаются.

Формат вывода
Если строки совпадают — выведите "yes", иначе — "no".
*/

#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::string str;
	std::cin >> str;

	std::vector<long long> h(str.length() + 1);
	std::vector<long long> x(str.length() + 1);

	const int p = 257;
	const int mod = 1000000007;

	h[0] = 0;
	x[0] = 1;

	for (int i = 0; i < str.length(); ++i) {
		h[i + 1] = (h[i] * p + (int)str[i]) % mod;
		x[i + 1] = (x[i] * p) % mod;
	}

	int q;
	std::cin >> q;

	while (q--) {
		int l, a, b;
		std::cin >> l >> a >> b;

		long long hashA = (h[a + l] + h[b] * x[l]) % mod;
		long long hashB = (h[b + l] + h[a] * x[l]) % mod;

		if (hashA == hashB)
			std::cout << "yes" << std::endl;
		else
			std::cout << "no" << std::endl;
	}

	return 0;
}
