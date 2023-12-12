/*
D. Анаграмма?
Задано две строки, нужно проверить, является ли одна анаграммой другой. Анаграммой называется строка, полученная из другой перестановкой букв.

Формат ввода
Строки состоят из строчных латинских букв, их длина не превосходит 100000. Каждая записана в отдельной строке.

Формат вывода
Выведите "YES" если одна из строк является анаграммой другой и "NO" в противном случае.
*/

#include <string>
#include <iostream>
#include <vector>

int main()
{
	std::string sa, sb;
	std::cin >> sa >> sb;

	if (sa.length() != sb.length())
	{
		std::cout << "NO" << std::endl;
		return 0;
	}

	std::vector<int> va(26,0);
	std::vector<int> vb(26,0);
	for (int i = 0; i < sa.length(); ++i)
	{
		va[sa[i] - 'a']++;
		vb[sb[i] - 'a']++;
	}
	if (va != vb)
		std::cout << "NO" << std::endl;
	else
		std::cout << "YES" << std::endl;

	return 0;
}