#include <iostream>
#include <string>
#include <stack>

int main()
{
	std::stack<int>		_st;
	std::string			str;
	int					n;
	while(std::cin >> str)
	{
		if (str == "push")
		{
			std::cin >> n;
			_st.push(n);
			std::cout << "ok" << std::endl;
		}
		else if (str == "pop")
		{
			if (_st.empty())
				std::cout << "error" << std::endl;
			else
			{
				std::cout << _st.top() << std::endl;
				_st.pop();
			}
		} 
		else if (str == "back")
		{
			if (_st.empty())
				std::cout << "error" << std::endl;
			else
				std::cout << _st.top() << std::endl;
		}
		else if (str == "size")
			std::cout << _st.size()<< std::endl;
		else if (str == "clear")
		{
			while(!_st.empty())
				_st.pop();
			std::cout << "ok" << std::endl;
		}
		else
		{
			std::cout << "bye" << std::endl;
			break;
		}
	}
	return 0;
}
