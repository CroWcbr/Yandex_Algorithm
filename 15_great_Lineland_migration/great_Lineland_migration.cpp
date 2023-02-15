#include <iostream>
#include <stack>
#include <vector>
#include <string>

int main()
{
	int	n;
	std::cin >> n;

	std::stack<std::pair<int, int>>		_st;
	std::vector<int>					_answer(n, -1);
	int									x;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> x;
		while(!_st.empty() && _st.top().first > x)
		{
			_answer[_st.top().second] = i;
			_st.pop();
		}
		_st.push(std::make_pair(x, i));
	}
	for (int i = 0; i < n; ++i)
	{
		std::cout << _answer[i];
		if (i != n - 1)
			std::cout << " ";
	}
	return 0;
}
