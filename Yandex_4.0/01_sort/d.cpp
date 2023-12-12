/*
D. Сортировка слиянием
Реализуйте сортировку слиянием, используя алгоритм из предыдущей задачи.
На каждом шаге делите массив на две части, сортируйте их независимо и сливайте с помощью уже реализованной функции.

Формат ввода
В первой строке входного файла содержится число N — количество элементов массива (0 ≤ N ≤ 10^6).
Во второй строке содержатся N целых чисел ai, разделенных пробелами (-10^9 ≤ ai ≤ 10^9).

Формат вывода
Выведите результат сортировки, то есть N целых чисел, разделенных пробелами, в порядке неубывания.
*/
#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int low, int mid, int high)
{
	int i, i1, i2;
	i = low;
	i1 = i2 = 0;

	std::vector<int> arr1(arr.begin() + low, arr.begin() + low + mid - low + 1);
	std::vector<int> arr2(arr.begin() + mid + 1, arr.begin() + 1 + high);

	while(i1 < arr1.size() && i2 < arr2.size())
		if (arr1[i1] > arr2[i2])
			arr[i++] = arr2[i2++];
		else
			arr[i++] = arr1[i1++];

	while (i1 < arr1.size())
		arr[i++] = arr1[i1++];
	while (i2 < arr2.size())
		arr[i++] = arr2[i2++];
}

void merge_sort(std::vector<int>& arr, int low, int high)
{
	if (low < high)
	{
		int middle = low + (high - low) / 2;
		merge_sort(arr, low, middle);
		merge_sort(arr, middle + 1, high);
		merge(arr, low, middle, high);
	}
}

int main()
{
	int n;
	std::cin >> n;

	std::vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		std::cin >> arr[i];

	merge_sort(arr, 0, n - 1);

	for (int i = 0; i < arr.size(); ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	return 0;
}
