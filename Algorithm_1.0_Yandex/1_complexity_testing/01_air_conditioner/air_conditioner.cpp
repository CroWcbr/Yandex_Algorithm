#include <iostream>
#include <string>

using namespace std;

int main() 
{
	int		troom;
	int		tcond;
	string	input;

	cin >> troom >> tcond >> input;
	if (input == "heat")
	{
		if (troom > tcond)
			cout << troom << endl;
		else
			cout << tcond << endl;
	}
	else if (input == "freeze")
	{
		if (troom > tcond)
			cout << tcond << endl;
		else
			cout << troom << endl;
	}
	else if (input == "auto")
		cout << tcond << endl;
	else if (input == "fan")
		cout << troom << endl;
	return 0;
}
