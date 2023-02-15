#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
 
int main()
{
	int n;
	std::cin >> n;
	std::vector<int> vec_n(n);
	for (int i = 0; i < n; i++)
		std::cin >> vec_n[i];
	std::sort(vec_n.begin(), vec_n.end());
	vec_n.erase(std::unique(vec_n.begin(), vec_n.end()), vec_n.end());

	int k;
	std::cin >> k;
	int p;
	for (int i = 0; i < k; i++) 
	{
		std::cin >> p;
		std::cout << std::distance(vec_n.begin(), std::lower_bound(vec_n.begin(), vec_n.end(), p)) << std::endl;
	}
	return 0;
}
