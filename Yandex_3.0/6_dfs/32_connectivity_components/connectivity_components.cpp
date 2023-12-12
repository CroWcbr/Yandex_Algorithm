#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>>		graph;
vector<bool>			visited;

void dfs(int now, vector<int> &component)
{
	visited[now] = true;
	component.push_back(now);
	for (int i : graph[now])
		if (!visited[i])
			dfs(i, component);
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

	vector<vector<int>> ans;
	for (int i = 1; i <= n; i++)
		if (!visited[i])
		{
			vector<int> tmp;
			dfs(i, tmp);
			ans.push_back(tmp);
		}
	cout << ans.size() << endl;
	for (vector<int> tmp : ans)
	{
		cout << tmp.size() << endl;
		sort(tmp.begin(), tmp.end());
		for (int v : tmp)
			cout << v << " ";
		cout << endl;
	}

	return 0;
}
