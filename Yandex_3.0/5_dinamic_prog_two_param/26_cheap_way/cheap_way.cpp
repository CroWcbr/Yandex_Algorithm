#include <iostream>

using namespace std;

int	answer(int n, int m)
{
	int t[n + 1][m + 1];
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
		{
			if (i == 0 || j == 0)
				t[i][j] = 1000000;
			else
				cin >> t[i][j];
		}
	t[0][0] = 0;
	t[0][1] = 0;
	t[1][0] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			t[i][j] = t[i][j] + min(t[i - 1][j], t[i][j - 1]);
	return t[n][m] ;
}

int main()
{
	int n, m;
	cin >> n >> m;
	cout << answer(n, m);
	return 0;
}
