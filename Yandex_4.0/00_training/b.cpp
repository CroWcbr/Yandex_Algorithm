/*
B. Сложить две дроби
Даны две рациональные дроби: a/b и c/d. Сложите их и результат представьте в виде несократимой дроби m/n.

Формат ввода
Программа получает на вход 4 натуральных числа a, b, c, d, каждое из которых не больше 100.

Формат вывода
Программа должна вывести два натуральных числа m и n такие, что m/n=a/b+c/d и дробь m/n – несократима.
*/

#include <iostream>
#include <numeric>

int main()
{
	int a, b, c, d;
	std::cin >> a >> b >> c >> d;

	int common_denominator = b * d;
	int numerator = (a * d) + (c * b);

	int greatest_common_divisor = std::gcd(numerator, common_denominator);

	int m = numerator / greatest_common_divisor;
	int n = common_denominator / greatest_common_divisor;

	std::cout << m << " " << n << std::endl;

	return 0;
}





