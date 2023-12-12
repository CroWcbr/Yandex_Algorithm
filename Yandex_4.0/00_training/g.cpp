/*
G. Кролик учит геометрию
Кролики очень любопытны. Они любят изучать геометрию, бегая по грядкам. Наш кролик как раз такой. Сегодня он решил изучить новую фигуру — квадрат.
Кролик бегает по грядке — клеточному полю N × M клеток. В некоторых из них посеяны морковки, в некоторых нет.
Помогите кролику найти сторону квадрата наибольшей площади, заполненного морковками полностью.

Формат ввода
В первой строке даны два натуральных числа N и M (, ). Далее в N строках расположено по M чисел, разделенных пробелами (число равно 0, если в клетке нет морковки или 1, если есть).

Формат вывода
Выведите одно число — сторону наибольшего квадрата, заполненного морковками.
*/

#include <iostream>

int main()
{
	int n, m;
	std::cin >> n >> m;
	int array[n][m];
	int x;
	int max = 0;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			std::cin >> x;
			if (i == 0 || j == 0)
				array[i][j] = x;
			else if (x == 0)
				array[i][j] = 0;
			else
			{
				array[i][j] = std::min(std::min(array[i - 1][j - 1], array[i - 1][j]), array[i][j - 1]) + x;
				if(array[i][j] > max)
					max = array[i][j];
			}
		}
	}
	std::cout << max << std::endl;
	return 0;
}
