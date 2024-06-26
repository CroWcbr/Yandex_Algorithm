/*
B. Футбольный комментатор
Раунд плей-офф между двумя командами состоит из двух матчей. Каждая команда проводит по одному матчу «дома» и «в гостях». Выигрывает команда, забившая большее число мячей. Если же число забитых мячей совпадает, выигрывает команд, забившая больше мячей «в гостях». Если и это число мячей совпадает, матч переходит в дополнительный тайм или серию пенальти.
Вам дан счёт первого матча, а также счёт текущей игры (которая ещё не завершилась). Помогите комментатору сообщить, сколько голов необходимо забить первой команде, чтобы победить, не переводя игру в дополнительное время.

Формат ввода
В первой строке записан счёт первого мачта в формате G1:G2, где G1 — число мячей, забитых первой командой, а G2 — число мячей, забитых второй командой. 
Во второй строке записан счёт второго (текущего) матча в аналогичном формате. Все числа в записи счёта не превышают 5.
В третьей строке записано число 1, если первую игру первая команда провела «дома», или 2, если «в гостях».

Формат вывода
Выведите единственное целое число — необходимое количество мячей.
*/

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