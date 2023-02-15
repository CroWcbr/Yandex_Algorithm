#include <iostream>
#include <string>
#include <map>

int main()
{
	std::map<char, uint64_t>	dict;
	std::string					str;
	size_t						len;

	std::cin >> str;
	len = str.size();
	for(size_t l = 0 , r = len - 1, cnt = 0; l < r; l++, r--)
	{
		uint64_t	tmp = (len + len - cnt) * (l + 1) / 2;
		dict[str[l]] += tmp;
		dict[str[r]] += tmp;
		cnt += 2;
	}
	if (len % 2 != 0)
		dict[str[len / 2]] += (len + 1) * (len / 2 + 1) / 2;
	for(auto &p : dict)
		std::cout << p.first << ": " << p.second << std::endl;
	return 0;
}
