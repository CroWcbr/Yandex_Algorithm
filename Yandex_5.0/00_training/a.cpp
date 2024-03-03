#include <iostream>

int main()
{
	int P, V, Q, M;
	std::cin >> P >> V >> Q >> M;

    long long int minV = P - V;
    long long int maxV = P + V;
    long long int minM = Q - M;
    long long int maxM = Q + M; 

    if (maxM < minV || minM > maxV)
        std::cout << maxV - minV + 1 + maxM - minM + 1 << std::endl;
    else if (minM >= minV && maxM <= maxV)
        std::cout << maxV - minV + 1 << std::endl;
    else if (minM <= minV && maxM >= maxV)
        std::cout << maxM - minM + 1 << std::endl;
    else if (minM < minV)
        std::cout << maxV - minM + 1 << std::endl;
    else if (maxM > maxV)
        std::cout << maxM - minV + 1 << std::endl;

    return 0;
}