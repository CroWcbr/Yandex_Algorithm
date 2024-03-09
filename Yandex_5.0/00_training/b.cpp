#include <iostream>

int main()
{
    int Gh1, Gg1, Gh2, Gg2, w;
    {
        char tmp;
        std::cin >> Gh1 >> tmp >> Gg2 >> Gg1 >> tmp >> Gh2 >> w;
    }
	
    if (w == 2)
    {
        std::swap(Gh1, Gg1);
        std::swap(Gh2, Gg2);
    }

    if (Gh1 + Gg1 > Gh2 + Gg2)
        std::cout << 0;
    else
    {
        int G1 = Gh1 + Gg1;
        int G2 = Gh2 + Gg2;

        int answer = G2 - G1;
// std::cout << G1 << "\t" << G2 << std::endl;
// std::cout << answer << std::endl;
// std::cout << Gh1 << "\t" << Gg1 << std::endl;
// std::cout << Gh2 << "\t" << Gg2 << std::endl;
        if (G1 == G2 && G1 == 0)
            answer++;
        else if (w == 2 && Gg1 <= Gg2)
                ++answer;
        if (G1 + answer == G2 && Gg1 + answer <= Gg2)
            ++answer;
        std::cout << answer;
    }

    return 0;
}