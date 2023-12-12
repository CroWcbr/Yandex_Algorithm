#include <iostream>
#include <vector>

using namespace std;

void	answer(int n)
{
	vector<int> vec(n + 1, 0);
	vector<int> prev(n + 1, 0);

	for (int i = 2; i <= n; i++)
	{
		vec[i] = vec[i - 1] + 1;
		prev[i] = i - 1;
		if (i % 3 == 0 && vec[i / 3] + 1 < vec[i])
		{
			vec[i] = vec[i / 3] + 1;
			prev[i] = i / 3;
		}
		else if (i % 2 == 0 && vec[i / 2] + 1 < vec[i])
		{
			vec[i] = vec[i / 2] + 1;
			prev[i] = i / 2;
		}
	}
	cout << vec[n] << endl;
	vector<int> way;
	way.push_back(n);
	while (n > 1) 
	{
		n = prev[n];
		way.push_back(n);
	}
	for (int i = way.size() - 1; i >= 0; i--)
	{
		cout << way[i];
		if ( i != 0)
			cout << " ";
	}
	cout << endl;
}

int main()
{
	int n;
	std::cin >> n;
	answer(n);
	return 0;
}
