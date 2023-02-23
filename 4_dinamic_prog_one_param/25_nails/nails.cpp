#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int	answer(int n)
{
	vector<uint32_t> vec(n + 1);
	vector<uint32_t> ans(n + 1, 0);

	for (int i = 1; i <= n; i++)
		cin >> vec[i];
	sort(vec.begin() + 1, vec.end());
	ans[2] = vec[2] - vec[1];
	ans[3] = vec[3] - vec[1];
	for (int i = 4; i <= n; i++)
		ans[i] = min(ans[i - 1], ans[i - 2]) + vec[i] - vec[i - 1];
	return ans[n];
}

int main()
{
	int n;
	cin >> n;
	cout << answer(n);
	return 0;
}
