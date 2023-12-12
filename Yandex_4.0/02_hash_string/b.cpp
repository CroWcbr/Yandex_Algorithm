/*
B. Основание строки
Строка S была записана много раз подряд, после чего от получившейся строки взяли префикс и дали вам. Ваша задача определить минимально возможную длину исходной строки S.

Формат ввода
В первой и единственной строке входного файла записана строка, которая содержит только латинские буквы, длина строки не превышает 50000 символов.

Формат вывода
Выведите ответ на задачу.
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

	int res = 1;
	int b;

	int a = 0;
	while (true)
	{
		b = res;
		while (b < str.length())
		{
			int len = res;
			if (b + len > str.length())
				len = str.length() - b;
			long long hashA = (h[a + len] + h[b] * x[len]) % mod;
			long long hashB = (h[b + len] + h[a] * x[len]) % mod;
			if (hashA != hashB)
				break;
			b += len;
		}

		if (b == str.length())
			break;
		++res;
	}
	std::cout << res << std::endl;

	return 0;
}
