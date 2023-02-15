#include <iostream>
#include <vector>

int main()
{
	int n, m, k;
	std::cin >> n >> m >> k;

	std::vector<int>	v(n * m);
	for (int i = 0; i < n * m; ++i)
		std::cin >> v[i];

	std::vector<int>	v_sum((n + 1) * (m + 1), 0);
	for (int r = 1; r <= n; r++)
		for (int c = 1; c <= m; c++)
			v_sum[r * m + c] = v_sum[(r - 1) * m + c] + \
								v_sum[r * m + c - 1] - \
								v_sum[(r - 1) * m + c - 1] + \
								v[(r - 1) * m + c - 1];

	int		x_min, x_max, y_min, y_max;
	for (int i_k = 0; i_k < k; ++i_k)
	{
		std::cin >> x_min >> y_min >> x_max >> y_max;
		std::cout << v_sum[x_max * m + y_max] - \
					v_sum[(x_min - 1) * m + y_max] - \
					v_sum[x_max * m + y_min - 1] + \
					v_sum[(x_min - 1)* m + y_min - 1] << std::endl;
	}
	return 0;
}
