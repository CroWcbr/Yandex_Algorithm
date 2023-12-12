#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int>>		graph;
vector<int>				indegree;

int main()
{
	int	n;
	int	m;
	cin >> n >> m;

	graph.resize(n + 1);
	indegree.resize(n + 1);
	int a;
	int b;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		indegree[b]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (indegree[i] == 0)
			q.push(i);

	vector<int> order;
	while (!q.empty())
	{
		int tmp = q.front();
		q.pop();
		order.push_back(tmp);
		for (int tmp_graph : graph[tmp])
		{
			indegree[tmp_graph]--;
			if (indegree[tmp_graph] == 0)
				q.push(tmp_graph);
		}
	}

	if (n == order.size())
	{
		for (int i = 0; i < n; i++)
			cout << order[i] << " ";
		cout << endl;
	}
	else
		cout << "-1" << endl;

	return (0);
}
