/*
C. Слияние
Базовый алгоритм для сортировки слиянием — алгоритм слияния двух упорядоченных массивов в один упорядоченный массив. Эта операция выполняется за линейное время с линейным потреблением памяти. Реализуйте слияние двух массивов в качестве первого шага для написания сортировки слиянием.

Формат ввода
В первой строке входного файла содержится число N — количество элементов первого массива (0 ≤ N ≤ 10^6).
Во второй строке содержатся N целых чисел ai, разделенных пробелами, отсортированные по неубыванию (-10^9 ≤ ai ≤ 10^9).
В третьей строке входного файла содержится число M — количество элементов второго массива (0 ≤ M ≤ 10^6).
В третьей строке содежатся M целых чисел bi, разделенных пробелами, отсортированные по неубыванию (-10^9 ≤ bi ≤ 10^9).

Формат вывода
Выведите результат слияния этих двух массивов, то есть M + N целых чисел, разделенных пробелами, в порядке неубывания.
*/
#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, std::vector<int>& arr1, std::vector<int>& arr2)
{
	int i, i1, i2;
	i = i1 = i2 = 0;
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

int main()
{
	int n;
	std::cin >> n;

	std::vector<int> arr1(n);
	for (int i = 0; i < n; ++i)
		std::cin >> arr1[i];

	int m;
	std::cin >> m;
	std::vector<int> arr2(m);
	for (int i = 0; i < m; ++i)
		std::cin >> arr2[i];

	std::vector<int> arr(m + n);
	merge(arr, arr1, arr2);

	for (int i = 0; i < arr.size(); ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	return 0;
}
