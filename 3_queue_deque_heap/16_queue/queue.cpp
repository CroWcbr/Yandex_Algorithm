#include <iostream>
#include <string>
#include <queue>

int main()
{
	std::queue<int>		_q;
	std::string			str;
	int					n;
	while(std::cin >> str)
	{
		if (str == "push")
		{
			std::cin >> n;
			_q.push(n);
			std::cout << "ok" << std::endl;
		}
		else if (str == "pop")
		{
			if (_q.empty())
				std::cout << "error" << std::endl;
			else
			{
				std::cout << _q.front() << std::endl;
				_q.pop();
			}
		} 
		else if (str == "front")
		{
			if (_q.empty())
				std::cout << "error" << std::endl;
			else
				std::cout << _q.front() << std::endl;
		}
		else if (str == "size")
			std::cout << _q.size()<< std::endl;
		else if (str == "clear")
		{
			while(!_q.empty())
				_q.pop();
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
