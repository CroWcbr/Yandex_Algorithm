#include <iostream>
#include <vector>

int main()
{
	int n;
	std::cin >> n;
	std::vector<uint64_t> c(n);
	for (int i = 0; i < n; i++)
		std::cin >> c[i];

	uint64_t result = 0;
	for (int i = 1; i < n; i++)
		result += std::min(c[i - 1], c[i]);
	std::cout << result;
	return 0;
}
