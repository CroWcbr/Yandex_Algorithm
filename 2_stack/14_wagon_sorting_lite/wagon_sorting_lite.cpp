#include <iostream>
#include <stack>
#include <string>

int main()
{
	int	n;
	std::cin >> n;
	
	std::stack<int>	_st;
	int				x;
	int				cnt = 1;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> x;
		_st.push(x);
		while(!_st.empty() && _st.top() == cnt)
		{
			cnt++;
			_st.pop();
		}
	}
	if (_st.empty())
		std::cout << "YES" << std::endl;
	else
		std::cout << "NO" << std::endl;
	return 0;
}
