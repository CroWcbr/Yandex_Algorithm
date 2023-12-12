#include <iostream>
#include <vector>

using namespace std;

int	answer(int n)
{
	vector<uint32_t> vec(n + 1);
	vec[1] = 2;
	vec[2] = 4;
	vec[3] = 7;
	for (int i = 4; i <= n; i++)
		vec[i] = vec[i - 1] + vec[i - 2] + vec[i - 3];
	return vec[n];
}

int main()
{
	int n;
	cin >> n;
	cout << answer(n);
	return 0;
}
