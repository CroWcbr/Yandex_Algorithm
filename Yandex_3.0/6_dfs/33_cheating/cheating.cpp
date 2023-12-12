#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>>		graph;
vector<int>				visited;
bool					error;

void dfs(int now, int colour)
{
	if (error)
		return;
	visited[now] = colour;
	for (int i : graph[now])
		if (!visited[i])
			dfs(i, 3 - colour);
		else if (visited[i] == visited[now])
			error = true;
}

int	main()
{
	int	n;
	int	m;
	cin >> n >> m;

	graph.resize(n + 1);
	visited.resize(n + 1);
	int a;
	int b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	error = false;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
			dfs(i, 1);
		if (error)
			break ;
	}

	if (error)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;

	return 0;
}
