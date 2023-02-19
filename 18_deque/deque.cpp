#include <iostream>
#include <string>
#include <deque>

int main()
{
	std::deque<int>		_d;
	std::string			str;
	int					n;
	while(std::cin >> str)
	{
		if (str == "push_front")
		{
			std::cin >> n;
			_d.push_front(n);
			std::cout << "ok" << std::endl;
		}
		else if (str == "push_back")
		{
			std::cin >> n;
			_d.push_back(n);
			std::cout << "ok" << std::endl;
		}
		else if (str == "pop_front")
		{
			if (_d.empty())
				std::cout << "error" << std::endl;
			else
			{
				std::cout << _d.front() << std::endl;
				_d.pop_front();
			}
		} 
		else if (str == "pop_back")
		{
			if (_d.empty())
				std::cout << "error" << std::endl;
			else
			{
				std::cout << _d.back() << std::endl;
				_d.pop_back();
			}
		} 
		else if (str == "front")
		{
			if (_d.empty())
				std::cout << "error" << std::endl;
			else
				std::cout << _d.front() << std::endl;
		}
		else if (str == "back")
		{
			if (_d.empty())
				std::cout << "error" << std::endl;
			else
				std::cout << _d.back() << std::endl;
		}
		else if (str == "size")
			std::cout << _d.size()<< std::endl;
		else if (str == "clear")
		{
			_d.clear();
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
