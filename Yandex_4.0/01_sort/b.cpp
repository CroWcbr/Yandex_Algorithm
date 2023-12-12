/*
B. Быстрая сортировка
Реализуйте быструю сортировку, используя алгоритм из предыдущей задачи.
На каждом шаге выбирайте опорный элемент и выполняйте partition относительно него. Затем рекурсивно запуститесь от двух частей, на которые разбился исходный массив.

Формат ввода
В первой строке входного файла содержится число N — количество элементов массива (0 ≤ N ≤ 10^6).
Во второй строке содержатся N целых чисел ai, разделенных пробелами (-10^9 ≤ ai ≤ 10^9).

Формат вывода
Выведите результат сортировки, то есть N целых чисел, разделенных пробелами.
*/
#include <iostream>
#include <vector>
#include <cstdlib>

int partition(std::vector<int>& arr, int low, int high)
{
	int random_position = low + rand() % (high - low + 1);
	int pivot = arr[random_position];
	int p_left = low;
	int p_right = low;
	while(low <= high)
	{
		if(arr[high] > pivot)
		{
			--high;
		}
		else if(arr[low] < pivot)
		{
			if (p_left != low)
			{
				std::swap(arr[p_right], arr[low]);
				std::swap(arr[p_right], arr[p_left]);
			}
			++low;
			++p_left;
			++p_right;
		}
		else if (arr[low] == pivot)
		{
			if (p_right != low)
			{
				std::swap(arr[p_right], arr[low]);
			}
			++low;
			++p_right;
		}
		else
			++low;
	}
	return (p_left);
}

void sort(std::vector<int>& data, int low, int high)
{
	if (low < high)
	{
		int pivot = partition(data, low, high);
		sort(data, low, pivot - 1);
		pivot;
		for (; pivot < high; ++pivot)
			if (data[pivot] != data[pivot + 1])
				break;
		sort(data, pivot + 1, high);
	}
}

int main()
{
	int n;
	std::cin >> n;

	std::vector<int> data(n);
	for (int i = 0; i < n; ++i)
		std::cin >> data[i];

	sort(data, 0, n - 1);

	for (int i = 0; i < n; ++i)
		std::cout << data[i] << " ";
	std::cout << std::endl;
	return 0;
}
