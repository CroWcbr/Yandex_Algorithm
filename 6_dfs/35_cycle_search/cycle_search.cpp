#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int>>	graph;
vector<int>			visited;
vector<int>			path;
bool				flag;

void dfs(int now, int last)
{
	if (flag)
		return;
	visited[now] = 1;
	path.push_back(now);
	for (int i : graph[now])
	{
		if (i == last)
			continue;
		if (visited[i])
		{
			path.push_back(i);
			flag = true;
			return;
		}
		else
			dfs(i, now);
		if (flag)
			return;
	}
	visited[now] = 2;
	path.pop_back();
}

int	main()
{
	int	n;
	cin >> n;

	graph.resize(n + 1);
	visited.resize(n + 1);
	int x;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
	{
		cin >> x;
		if (x)
			graph[i].push_back(j);
	}

	flag = false;
	for (int i = 1; i <= n; i++)
		if (!visited[i])
		{
			dfs(i, 0);
			if (flag)
				break;
		}

	if (flag)
	{
		cout << "YES" << endl;
		vector<int> answer;
		answer.push_back(path.back());
		size_t i = path.size() - 2;
		while (path[i] != path.back()) {
			answer.push_back(path[i]);
			--i;
		}
		std::cout << answer.size() << std::endl;
		for (int i : answer)
			cout << i << " ";
		cout << endl;
	}
	else
		cout << "NO" << endl;

	return 0;
}
