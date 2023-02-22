#include <iostream>
#include <string>
#include <vector>


int main()
{
	int k;
	std::string s;
	std::cin >> k >> s;

	std::vector<int> w(26, 0);
	int	max = 0;
	int	p = 0;
	for (int i = 0; i < s.size(); i++) 
	{
		max = std::max(max, ++w[s[i] - 'a']);
		if (max + k - 1 < i - p) 
		{
			w[s[p] - 'a']--;
			p++;
		}
	}
	std::cout << s.size() - p;
	return 0;
}
