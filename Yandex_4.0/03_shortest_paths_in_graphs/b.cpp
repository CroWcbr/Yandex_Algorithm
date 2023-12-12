/*
B. Дейкстра с восстановлением пути
Дан ориентированный взвешенный граф. Найдите кратчайший путь от одной заданной вершины до другой

Формат ввода
В первой строке содержатся три числа: N, S и F (1 ≤ N ≤ 100, 1 ≤ S, F ≤ N), где N — количество вершин графа, S — начальная вершина, а F — конечная. В следующих N строках вводится по N чисел, не превосходящих 100, – матрица смежности графа, где -1 означает, что ребра между вершинами нет, а любое неотрицательное число — наличие ребра данного веса. На главной диагонали матрицы записаны нули.

Формат вывода
Последовательно выведите все вершины одного (любого) из кратчайших путей, или -1, если пути между указанными вершинами не существует
*/

#include <iostream>
#include <vector>
#include <set>
#include <stack>

int main()
{
	int n, s, f;
	std::cin >> n >> s >> f;

	std::vector<std::vector<int>> data(n + 1, std::vector<int>(n + 1));

	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= n; ++j)
			if (i == 0 || j == 0)
				data[i][j] = 0;
			else
				std::cin >> data[i][j];

	std::vector<bool>	visited(n + 1, false);
	std::vector<int>	dist(n + 1, 100000);
	std::vector<int>	prev(n + 1, -1);

	dist[s] = 0;
	std::set<int> v;
	while (1)
	{
		// result
		if (s == f)
		{
			std::stack<int> result;
			while(1)
			{
				if (f == -1)
					break;
				result.push(f);
				f = prev[f];
			}
			while (!result.empty())
			{
				std::cout << result.top() << " ";
				result.pop();
			}
			std::cout << std::endl;
			break;
		}

		visited[s] = true;
		// algorithm
		for (int i = 1; i <= n; ++i)
		{
			if (s == i)
				continue ;
			else if(data[s][i] == -1)
				continue ;
			else if (dist[i] > dist[s] + data[s][i])
			{
				dist[i] = dist[s] + data[s][i];
				prev[i] = s;
			}
			if (visited[i] == false)
				v.insert(i);
		}
		// check
		if (v.empty())
		{
			std::cout << -1 << std::endl;
			break;
		}

		// find next
		int min = *v.begin();
		for (auto i : v)
			if (dist[min] > dist[i])
				min = i;

		s = min;
		v.erase(v.find(s));
	}

	return 0;
}
