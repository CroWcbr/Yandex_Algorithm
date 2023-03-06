#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int dx[] = {1, 0, 0, -1, 0, 0};
const int dy[] = {0, 1, 0, 0, -1, 0};
const int dz[] = {0, 0, 1, 0, 0, -1};

const int MAXN = 30;
char	cave[MAXN][MAXN][MAXN];
bool	visited[MAXN][MAXN][MAXN];
int		dist[MAXN][MAXN][MAXN];

struct point 
{
	int x;
	int y;
	int z;
};

int bfs(int n, int x, int y, int z)
{
	queue<point>	q;
	q.push({x, y, z});
	visited[x][y][z] = true;
	dist[x][y][z] = 0;
	while (!q.empty())
	{
		point	p = q.front();
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			int nx = p.x + dx[i];
			int ny = p.y + dy[i];
			int nz = p.z + dz[i];

			if (nx >= 0 && nx < n && \
				ny >= 0 && ny < n && \
				nz >= 0 && nz < n && \
				cave[nx][ny][nz] == '.' && \
				!visited[nx][ny][nz]) 
			{
				q.push({nx, ny, nz});
				visited[nx][ny][nz] = true;
				dist[nx][ny][nz] = dist[p.x][p.y][p.z] + 1;
				if (nz == n - 1)
					return dist[nx][ny][nz];
			}
		}
	}
	return -1;
}

int main()
{
	int	n;
	cin >> n;
	int startx, starty, startz;

	char c;
	for (int z = n - 1; z >= 0; z--)
	{
		for (int x = 0; x < n; x++)
		{
			for (int y = 0; y < n; )
			{
				cin.get(c);
				if (c != '.' && c != '#' && c != 'S')
					continue;
				cave[x][y][z] = c;
				if (c == 'S')
				{
					startx = x;
					starty = y;
					startz = z;
				}
				y++;
			}
		}
	}
	cout << bfs(n, startx, starty, startz) << endl;
	return 0;
}
