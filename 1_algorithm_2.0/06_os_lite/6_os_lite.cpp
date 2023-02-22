#include <iostream>
#include <vector>

int main()
{
	int m;
	std::cin >> m;
	int n;
	std::cin >> n;
	
	if (n == 0)
		std::cout << 0;
	else
	{
		std::vector<std::pair<int, int>> result;
		int x, y;
		for (int i = 0; i < n; i++)
		{
			std::cin >> x >> y;
			for (auto it = result.begin(); it != result.end(); )
			{
				if (it->first > y || it->second < x)
					++it;
				else
					it = result.erase(it);
			}
			result.push_back(std::make_pair(x,y));
		}
		std::cout << result.size();
	}
	return 0;
}
