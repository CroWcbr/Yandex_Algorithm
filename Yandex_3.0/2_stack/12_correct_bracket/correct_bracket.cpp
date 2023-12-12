#include <iostream>
#include <string>
#include <stack>

int main()
{
	std::stack<char>	_st;
	std::string			str;
	std::string			answer = "yes";

	std::cin >> str;
	for (const auto &c : str)
	{
		if (c == '(' || c == '[' || c == '{')
			_st.push(c);
		else if (!_st.empty() && 
				((c == ')' && _st.top() == '(') || \
				(c == ']' && _st.top() == '[') || \
				(c == '}' && _st.top() == '{')))
			_st.pop();
		else
		{
			answer = "no";
			break;
		}
	}
	if (!_st.empty())
		answer = "no";
	std::cout << answer << std::endl;
	return 0;
}
