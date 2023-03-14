#include <iostream>
#include <string>

using namespace std;

int main() 
{
	string	t[4];
	char tmp;
	for (int i = 0; i < 4; i++)
	{
		t[i] = "";
		while ((tmp = getchar()) != '\n')
			if (tmp >= '0' && tmp <= '9')
				t[i] += tmp;
		if (t[i].size() == 7)
			t[i] = "8495" + t[i];
		else if (t[i][0] == '7')
			t[i][0] = '8';
	}
	for (int i = 1; i < 4; i++)
	{
		if (t[0] == t[i])
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
