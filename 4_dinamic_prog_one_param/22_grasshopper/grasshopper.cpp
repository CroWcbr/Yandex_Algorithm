#include <iostream>
#include <vector>

using namespace std;

int answer(int n, int k)
{
	int			i;
	vector<uint64_t>	vec(n + 1, 0);
	vec[1] = 1;
	for (int i = 2; i <= n; i++) 
		for (int j = 1; j <= k; j++)
			if (i - j >= 1)
				vec[i] += vec[i - j];
	return vec[n];
}

int main()
{
	int n, k;
	std::cin >> n >> k;
	cout << answer(n, k);
	return 0;
}
