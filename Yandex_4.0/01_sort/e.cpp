/*
E. Поразрядная сортировка
Поразрядная сортировка является одним из видов сортировки, которые работают практически за линейное от размера сортируемого массива время. Такая скорость достигается за счет того, что эта сортировка использует внутреннюю структуру сортируемых объектов. Изначально этот алгоритм использовался для сортировки перфокарт. Первая его компьютерная реализация была создана в университете MIT Гарольдом Сьюардом (Harold Н. Seward). Опишем алгоритм подробнее. Пусть задан массив строк s1 , ..., si причём все строки имеют одинаковую длину m. Работа алгоритма состоит из m фаз. На i -ой фазе строки сортируются па i -ой с конца букве. Происходит это следующим образом. Будем, для простоты, в этой задаче рассматривать строки из цифр от 0 до 9. Для каждой цифры создается «корзина» («bucket»), после чего строки si распределяются по «корзинам» в соответствии с i-ой цифрой с конца. Строки, у которых i-ая с конца цифра равна j попадают в j-ую корзину (например, строка 123 на первой фазе попадет в третью корзину, на второй — во вторую, на третьей — в первую). После этого элементы извлекаются из корзин в порядке увеличения номера корзины. Таким образом, после первой фазы строки отсортированы по последней цифре, после двух фаз — по двум последним, ..., после m фаз — по всем. При важно, чтобы элементы в корзинах сохраняли тот же порядок, что и в исходном массиве (до начала этой фазы). Например, если массив до первой фазы имеет вид: 111, 112, 211, 311, то элементы по корзинам распределятся следующим образом: в первой корзине будет. 111, 211, 311, а второй: 112. Напишите программу, детально показывающую работу этого алгоритма на заданном массиве.

Формат ввода
Первая строка входного файла содержит целое число n (1 ≤ n ≤ 1000) . Последующие n строк содержат каждая по одной строке si . Длины всех si , одинаковы и не превосходят 20. Все si состоят только из цифр от 0 до 9.

Формат вывода
В выходной файл выведите исходный массив строк в, состояние «корзин» после распределения элементов по ним для каждой фазы и отсортированный массив. Следуйте формату, приведенному в примере.
*/
#include <iostream>
#include <vector>
#include <string>

int main()
{
	int n;
	std::cin >> n;

	std::vector<std::string> arr(n);
	for (int i = 0; i < n; ++i)
		std::cin >> arr[i];

	std::cout << "Initial array:" << std::endl;
	for (int i = 0; i < n; ++i)
	{
		std::cout << arr[i];
		if (i == n - 1)
			std::cout<< std::endl;
		else
			std::cout << ", ";
	}
	std::cout << "**********" << std::endl;

	int len = arr[0].size();
	for (int i = len - 1; i >= 0; --i)
	{
		std::vector<std::string> tmp(arr);
		std::cout << "Phase " << len - i << std::endl;

		std::vector<int> count_arr(10, 0);
		for (int k = 0; k < arr.size(); ++k)
			count_arr[arr[k][i] - '0']++;

		// for (int i = 0; i < count_arr.size(); ++i)
		// {
		// 	std::cout << count_arr[i];
		// 	if (i == count_arr.size() - 1)
		// 		std::cout<< std::endl;
		// 	else
		// 		std::cout << ", ";
		// }

		std::vector<int> position_arr(10, 0);
		int pos = 0;
		for (int k = 0; k < count_arr.size(); ++k)
		{
			position_arr[k] = count_arr[k] ? pos : 0;
			pos += count_arr[k];
		}

		// for (int i = 0; i < position_arr.size(); ++i)
		// {
		// 	std::cout << position_arr[i];
		// 	if (i == position_arr.size() - 1)
		// 		std::cout<< std::endl;
		// 	else
		// 		std::cout << ", ";
		// }

		for (int k = 0; k < tmp.size(); ++k)
			arr[position_arr[tmp[k][i] - '0']++] = tmp[k];

		pos = 0;
		for (int k = 0; k < count_arr.size(); ++k)
		{
			std::cout << "Bucket " << k << ": ";
			if (count_arr[k] == 0)
				std::cout << "empty" << std::endl;
			else
			{
				for (int j = 0; j < count_arr[k]; ++j)
				{
					std::cout << arr[pos++];
					if (j == count_arr[k] - 1)
						std::cout<< std::endl;
					else
						std::cout << ", ";
				}
			}
		}

		// for (int i = 0; i < n; ++i)
		// {
		// 	std::cout << arr[i];
		// 	if (i == n - 1)
		// 		std::cout<< std::endl;
		// 	else
		// 		std::cout << ", ";
		// }
		std::cout << "**********" << std::endl;
	}


	std::cout << "Sorted array:" << std::endl;
	for (int i = 0; i < n; ++i)
	{
		std::cout << arr[i];
		if (i == n - 1)
			std::cout<< std::endl;
		else
			std::cout << ", ";
	}

	return 0;
}
