#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int					n;
vector<int>			dist;
vector<int>			pred;
vector<vector<int>>	adj;

void bfs(int s)
{
	queue<int>	q;
	q.push(s);
	dist[s] = 0;
	pred[s] = -1;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int v = 1; v <= n; v++)
		{
			if (adj[u][v] && dist[v] == -1) 
			{
				q.push(v);
				dist[v] = dist[u] + 1;
				pred[v] = u;
			}
		}
	}
}

int main()
{
	cin >> n;
	dist.resize(n + 1, -1);
	pred.resize(n + 1);
	adj.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		adj[i].resize(n + 1);
		for (int j = 1; j <= n; j++)
			cin >> adj[i][j];
	}
	int start, finish;
	cin >> start >> finish;

	bfs(start);

	if (dist[finish] == -1)
		cout << "-1" << endl;
	else
		cout << dist[finish] << endl;
	return 0;
}
