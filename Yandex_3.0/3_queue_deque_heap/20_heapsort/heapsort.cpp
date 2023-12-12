#include <iostream>
#include <vector>

void heapify(std::vector<int>& arr, int n, int i)
{
	int	largest = i; 
	int	l = 2 * i + 1;
	int	r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;
	if (largest != i)
	{
		std::swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

int main()
{
	int n;
	std::cin >> n;

	std::vector<int>	arr(n);
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i >= 0; i--)
	{
		std::swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}

	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}
