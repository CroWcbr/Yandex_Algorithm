/*
C. Быстрый алгоритм Дейкстры
Дан ориентированный взвешенный граф. Найдите кратчайшее расстояние от одной заданной вершины до другой.

Формат ввода
Сеть дорог задана во входном файле следующим образом: первая строка содержит числа N и K (1 ≤ N ≤ 100000, 0 ≤ K ≤ 300000), где K – количество дорог. Каждая из следующих K строк содержит описание дороги с двусторонним движением – три целых числа ai, bi и li (1 ≤ ai, bi ≤ N, 1 ≤ li ≤ 10^6). Это означает, что имеется дорога длины li, которая ведет из города ai в город bi. В последней строке находятся два числа А и В – номера городов, между которыми надо посчитать кратчайшее расстояние (1 ≤ A, B ≤ N)
Формат вывода
Выведите одно число – расстояние между нужными городами. Если по дорогам от города А до города В доехать невозможно, выведите –1.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <functional>

struct Edge
{
	int destination;
	int weight;
};

int main()
{
	std::ifstream input("input.txt");
	int n, k;
	input >> n >> k;

	std::vector<std::vector<Edge>> data(n + 1);

	int a, b, l;
	for (int i = 0; i < k; ++i) {
		input >> a >> b >> l;
		data[a].push_back({b, l});
		data[b].push_back({a, l});
	}

	int s, f;
	input >> s >> f;
	input.close();

	std::vector<bool> visited(n + 1, false);
	std::vector<long long int> dist(n + 1, -1);

	dist[s] = 0;
	std::priority_queue<std::pair<long long int, long long int>, std::vector<std::pair<long long int, long long int>>, std::greater<std::pair<long long int, long long int>>> pq;
	pq.push({0, s});

	while (!pq.empty()) {
		long long int cur_dist = pq.top().first;
		long long int cur_node = pq.top().second;
		pq.pop();

		if (visited[cur_node])
			continue;

		visited[cur_node] = true;

		for (const auto& edge : data[cur_node])
		{
			long long int neighbor_node = edge.destination;
			long long int edge_weight = edge.weight;

			if (!visited[neighbor_node] && (dist[neighbor_node] == -1 || dist[neighbor_node] > cur_dist + edge_weight))
			{
				dist[neighbor_node] = cur_dist + edge_weight;
				pq.push({dist[neighbor_node], neighbor_node});
			}
		}
	}

	if (dist[f] == -1) {
		std::cout << -1 << std::endl;
	} else {
		std::cout << dist[f] << std::endl;
	}

	return 0;
}
