#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

void answer(int n)
{
	vector<int>	costs(n);
	for (int i = 0; i < n; i++)
		cin >> costs[i];

	vector<vector<int>>				dp(n + 1, vector<int>(n + 1, 100000000));
	vector<vector<pair<int, int>>>	pr(n + 1, vector<pair<int, int>>(n + 1, make_pair(-1, -1)));
	if (costs[0] > 100) 
		{
			dp[1][0] = costs[0];
			dp[0][1] = costs[0];
			pr[0][1] = make_pair(1, 0);
		} 
		else
			dp[0][0] = costs[0];

	for (int j = 0; j < n - 1; j++)
		for (int i = 0; i < n; i++)
		{
			if (costs[j + 1] > 100 && \
				i < n - 1 && \
				dp[i][j] + costs[j + 1] < dp[i + 1][j + 1])
			{
				dp[i + 1][j + 1] = dp[i][j] + costs[j + 1];
				pr[i + 1][j + 1] = make_pair(i, j);
			}
			else if (dp[i][j] + costs[j + 1] < dp[i][j + 1])
			{
				dp[i][j + 1] = dp[i][j] + costs[j + 1];
				pr[i][j + 1] = make_pair(i, j);
			}
			if (i > 0 && \
				dp[i][j] < dp[i - 1][j + 1])
			{
				dp[i - 1][j + 1] = dp[i][j];
				pr[i - 1][j + 1] = make_pair(i, j);
			}
		}

	int	coupons_left = 0;
	int	min_cost_sum = 100000000;
	for (int i = n; i >= 0; i--)
		if (min_cost_sum > dp[i][n - 1])
		{
			min_cost_sum = dp[i][n - 1];
			coupons_left = i;
		}
	cout << min_cost_sum << endl;

	vector<int> coupons_lost_days;
	for (int i = coupons_left, j = n - 1; i > -1 || j > -1;)
	{
		int pr_i = i;
		int pr_j = j;
		i = pr[i][j].first;
		j = pr[pr_i][pr_j].second;
		if (i > pr_i)
			coupons_lost_days.push_back(pr_j + 1);
	}

	cout << coupons_left << " " << coupons_lost_days.size() << endl;
	for (int i = coupons_lost_days.size() - 1; i >= 0; i--)
		cout << coupons_lost_days[i] << " ";
	cout << endl;
}

int main() 
{
	int n;
	cin >> n;
	if (n == 0)
		cout << "0\n0 0\n";
	else
		answer(n);
	return 0;
}
