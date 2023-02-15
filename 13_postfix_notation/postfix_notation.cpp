#include <iostream>
#include <stack>
#include <string>
#include <sstream>

int main()
{
	std::string	str;
	std::stack<int>	_st;
	getline(std::cin, str);
	
	std::stringstream	ss(str);
	std::string			item;
	while(std::getline(ss, item, ' '))
	{
		if (item == "+" || item == "-" || item == "*")
		{
			int	a = _st.top();
			_st.pop();
			int	b = _st.top();
			_st.pop();
			if (item == "+")
				_st.push(a + b);
			else if (item == "-")
				_st.push(b - a);
			else
				_st.push(a * b);
		}
		else
			_st.push(std::stoi(item));
	}
	std::cout << _st.top() << std::endl;
	return 0;
}
