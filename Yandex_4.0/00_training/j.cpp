/*
J. Групповой проект
Всего студентов по направлению «Мировая культура» — n человек. Преподаватель дал задание — групповой проект. Для выполнения этого задания студенты должны разбиться на группы численностью от a до b человек. Скажите, можно ли разбить всех студентов на группы для выполнения проекта или преподаватель что-то перепутал.

Формат ввода
В первой строке вводится число t (1 ≤ t ≤ 100) — количество тестовых случаев. Далее для каждого тестового случая вводится 3 целых числа n, a и b (1 ≤ n ≤ 10^9, 1 ≤ a ≤ b ≤ n) — общее число студентов и ограничение на число студентов в одной группе.

Формат вывода
Для каждого тестового случая выведите "YES", если можно разбить студентов на группы и "NO", если нельзя.
*/

#include <iostream>

int main()
{
	int t;
	std::cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n, a, b;
		std::cin >> n >> a >> b;
		long int ost = n % a;
		long int gr = n / a;
		long int delta = b - a;
		if (delta * gr >= ost)
			std::cout << "YES" << std::endl;
		else
			std::cout << "NO" << std::endl;
	}

	return 0;
}
