#include <iostream>
#include <stack>
#include <map>

using namespace std;

int main()
{
	uint64_t	n;
	cin >> n;

	stack<pair<uint64_t, string>>	train;
	map<string, uint64_t>			cnt;

	for (uint64_t i = 0; i < n; i++)
	{
		string	op;
		cin >> op;

		if (op == "add")
		{
			uint64_t		k;
			cin >> k;
			string	tovar;
			char tmp;
			getchar();
			while ((tmp = getchar()) != '\n')
				tovar.push_back(tmp);
			train.push(make_pair(k, tovar));
			cnt[tovar] += k;
		}
		else if (op == "delete")
		{
			uint64_t	k;
			cin >> k;
			while (k > 0 && !train.empty())
			{
				uint64_t curr_cnt = train.top().first;
				string curr_cargo = train.top().second;
				if (curr_cnt <= k)
				{
					k -= curr_cnt;
					cnt[curr_cargo] -= curr_cnt;
					train.pop();
				}
				else
				{
					cnt[curr_cargo] -= k;
					train.top().first -= k;
					k = 0;
				}
			}
		}
		else if (op == "get")
		{
			string	tovar;
			cin >> tovar;
			cout << cnt[tovar] << endl;
		}
	}

	return 0;
}
