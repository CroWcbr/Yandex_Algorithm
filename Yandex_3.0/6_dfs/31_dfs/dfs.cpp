#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>>		graph;
vector<bool>			visited;

void dfs(int now)
{
	visited[now] = true;
	for (int i : graph[now])
		if (!visited[i])
			dfs(i);
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
	dfs(1);

	vector<int> ans;
	for (int i = 1; i <= n; i++)
		if (visited[i])
			ans.push_back(i);
	cout << ans.size() << endl;
	for (int i : ans)
		cout << i << " ";
	cout << endl;

	return 0;
}
