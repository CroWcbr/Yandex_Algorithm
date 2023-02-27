#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void	answer(int n, int m)
{
	int t[n + 1][m + 1];
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (i == 0 || j == 0)
				t[i][j] = -1;
			else
				cin >> t[i][j];
		}
	}
	t[0][0] = 0;
	t[0][1] = 0;
	t[1][0] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			t[i][j] = t[i][j] + max(t[i - 1][j], t[i][j - 1]);

	cout << t[n][m] << endl;

	vector<char>	way;
	for (int i = n, j = m; !(i == 1 && j == 1); )
	{
		if (t[i - 1][j] > t[i][j - 1])
		{
			way.push_back('D');
			i--;
		}
		else
		{
			way.push_back('R');
			j--;
		}
	}

	for (int i = way.size() - 1; i >= 0; i--)
	{
		cout << way[i];
		if (i != 0)
			cout << " ";
	}
	cout << endl;;
}

int main()
{
	int n, m;
	cin >> n >> m;
	answer(n, m);
	return 0;
}
