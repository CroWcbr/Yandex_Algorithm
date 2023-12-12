#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void	answer(int n, int m, int *n_arr, int *m_arr)
{
	int t[n + 1][m + 1];

	for (int i = 0; i <= n; i++)
		t[i][0] = 0;
	for (int j = 0; j <= m; j++)
		t[0][j] = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (n_arr[i] == m_arr[j])
				t[i][j] = 1 + t[i - 1][j - 1];
			else
				t[i][j] = max(t[i - 1][j], t[i][j - 1]);
		}
	}

	vector<int>	way;
	for (int i = n, j = m; i > 0 && j > 0; )
	{
		if (n_arr[i] == m_arr[j])
		{
			way.push_back(n_arr[i]);
			i--;
			j--;
		}
		else if (t[i - 1][j] > t[i][j - 1])
			i--;
		else
			j--;
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
	int n;
	cin >> n;
	int n_arr[1001];
	for (int i = 1; i <= n; i++)
		cin >> n_arr[i];
	int m;
	cin >> m;
	int m_arr[1001];
	for (int i = 1; i <= m; i++)
		cin >> m_arr[i];
	answer(n, m, n_arr, m_arr);
	return 0;
}
