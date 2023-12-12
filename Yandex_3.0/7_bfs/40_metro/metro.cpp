#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int	n;
	cin >> n;
	int	m;
	cin >> m;

	vector<vector<int>> metro(m + 1);
	for (int i = 1; i <= m; i++)
	{
		int p;
		cin >> p;
		for (int j = 0; j < p; j++)
		{
			int station;
			cin >> station;
			metro[i].push_back(station);
		}
	}
	int a, b;
	cin >> a >> b;

	int	metro_smez[n + 1][n + 1];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			metro_smez[i][j] = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < metro[i].size(); j++)
		{
			for (int k = 0; k < metro[i].size(); k++)
			{
				metro_smez[(metro[i][j])][(metro[i][k])] = 1;
				metro_smez[(metro[i][k])][(metro[i][j])] = 1;
			}
		}
	}

	queue<int>	q;
	q.push(a);
	vector<int> path(n + 1, -1);
	path[a] = 0;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (cur == b)
			break;
		for (int i = 1; i <= n; i++)
		{
			if (metro_smez[cur][i] != 0 && path[i] == -1)
			{
				if (cur == a)
					path[i] = 0;
				else
					path[i] = path[cur] + 1;
				q.push(i);
			}
		}
	}
	cout << path[b] << endl;
	return 0;
}
