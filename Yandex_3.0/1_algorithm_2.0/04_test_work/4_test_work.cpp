#include <iostream>

int main()
{
	int n, k, row_p, col_p;
	std::cin >> n >> k >> row_p >> col_p;

	int row_col = row_p * 2 - col_p % 2;
	int row_col_prev = row_col - k;
	int row_col_next = row_col + k;
	int row_prev = (row_col_prev + 1) / 2;
	int row_next = (row_col_next + 1) / 2;

	if (row_col_prev > 0 and (row_col_next > n || abs(row_prev - row_p) < abs(row_next - row_p)))
		std::cout << row_prev << " " << 2 - row_col_prev % 2 << std::endl;
	else if (row_col_next <= n)
		std::cout << row_next << " " << 2 - row_col_next % 2 << std::endl;
	else
		std::cout << "-1" << std::endl;

	return 0;
}
