#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
	int a, b, c;
	cin >> a >> b >> c;

	if (c < 0)
		cout << "NO SOLUTION" << endl;
	else if (a == 0 && b == c * c)
		cout << "MANY SOLUTIONS" << endl;
	else if (a == 0 && b != c * c)
		cout << "NO SOLUTION" << endl;
	else if ((c * c - b) % a)
		cout << "NO SOLUTION" << endl;
	else
		cout << round((c * c - b) / a) << endl;
	return 0;
}
