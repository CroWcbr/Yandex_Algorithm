#include <iostream>
#include <vector>

using namespace std;

int answer(int n)
{
	vector<int>	A(n + 1);
	vector<int>	B(n + 1);
	vector<int>	C(n + 1);
	vector<int>	t(n + 1);

	for (int i = 1; i <= n; i++)
		cin >> A[i] >> B[i] >> C[i];
	t[0] = 0;
	t[1] = A[1];
	if (n > 1)
	{
		t[2] = min(A[1] + A[2], B[1]);
		for(int i = 3; i <= n; i++)
			t[i] = min(min(t[i - 1] + A[i], t[i - 2] + B[i - 1]), t[i - 3] + C[i - 2]);
	}
	return t[n];
}

int main()
{
	int n;
	std::cin >> n;
	cout << answer(n);
	return 0;
}
