#include <iostream>

using namespace std;

int	answer(int n, int m)
{
	int t[n + 1][m + 1];

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			t[i][j] = 0;
	t[1][1] = 1;

	for (int i = 2; i <= n; i++)
		for (int j = 2; j <= m; j++)
			t[i][j] =  t[i - 1][j - 2] + t[i - 2][j - 1];

	return t[n][m];
}

int main()
{
	int n, m;
	cin >> n >> m;
	cout << answer(n, m);
	return 0;
}
