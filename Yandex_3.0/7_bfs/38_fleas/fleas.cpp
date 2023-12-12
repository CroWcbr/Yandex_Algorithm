#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct point 
{
	int x;
	int y;
};

vector<vector<int>>	dist;
vector<point>		adj;

const int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

void bfs(int n, int m, int s, int t)
{
	queue<point>	q;
	q.push({s, t});
	dist[s][t] = 0;
	while (!q.empty())
	{
		point	p = q.front();
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int nx = p.x + dx[i];
			int ny = p.y + dy[i];
			if (nx < 1 || nx > n || ny < 1 || ny > m)
				continue;
			if (dist[nx][ny] == -1)
			{
				dist[nx][ny] = dist[p.x][p.y] + 1;
				q.push({nx, ny});
			}
		}
	}
}

void create_dist(int n, int m, int s, int t)
{
	dist.resize(n + 1);
	for (int i = 1; i <= n; i++)
		dist[i].resize(m + 1, -1);
	bfs(n, m, s, t);
}

int main()
{
	int	n, m;
	cin >> n >> m;
	int	s, t;
	cin >> s >> t;
	int	q;
	cin >> q;
	create_dist(n, m, s, t);

	adj.resize(q);
	int x, y;
	for (int i = 0; i < q; i++)
	{
		cin >> x >> y;
		adj[i] = {x, y};
	}

	int answer = 0;
	for (auto p : adj)
	{
		if (dist[p.x][p.y] == -1)
		{
			answer = -1;
			break;
		}
		else
			answer += dist[p.x][p.y];
	}
	cout << answer << endl;
	return 0;
}
