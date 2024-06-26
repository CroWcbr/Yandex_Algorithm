/*
D. Слоны и ладьи
На шахматной доске стоят слоны и ладьи, необходимо посчитать, сколько клеток не бьется ни одной из фигур.
Шахматная доска имеет размеры 8 на 8. Ладья бьет все клетки горизонтали и вертикали, проходящих через клетку, где она стоит, до первой встретившейся фигуры. Слон бьет все клетки обеих диагоналей, проходящих через клетку, где он стоит, до первой встретившейся фигуры.

Формат ввода
В первых восьми строках ввода описывается шахматная доска. Первые восемь символов каждой из этих строк описывают состояние соответствующей горизонтали: символ B (заглавная латинская буква) означает, что в клетке стоит слон, символ R — ладья, символ * — что клетка пуста. После описания горизонтали в строке могут идти пробелы, однако длина каждой строки не превышает 250 символов. После описания доски в файле могут быть пустые строки.

Формат вывода
Выведите количество пустых клеток, которые не бьются ни одной из фигур.
*/

#include <iostream>
#include <vector>
#include <string>

void update(const std::vector<char>& d, std::vector<bool>& a, int r, int c, int dr, int dc)
{
    a[r * 8 + c] = true;
    r += dr;
    c += dc;
    while (r >= 0 && r < 8 && c >= 0 && c < 8)
    {
        if (d[r * 8 + c] == '*')
            a[r * 8 + c] = true;
        else
            break;
        r += dr;
        c += dc;
    }
}

int main()
{
    std::vector<char> d(64);

    char ch;
    for (int r = 0; r < 8; ++r)
    {
        for (int c = 0; c < 8;)
        {
            std::cin >> ch;
            if (ch == 'R' || ch == 'B' || ch == '*')
                d[r * 8 + c++] = ch;
        }
    }

    std::vector<bool> a(64, false);
    for (int r = 0; r < 8; ++r)
    {
        for (int c = 0; c < 8; ++c)
        {
            if (d[r * 8 + c] == 'R')
            {
                update(d, a, r, c, 0, -1);
                update(d, a, r, c, 0, 1);
                update(d, a, r, c, -1, 0);
                update(d, a, r, c, 1, 0);
            }
            else if (d[r * 8 + c] == 'B')
            {
                update(d, a, r, c, -1, -1);
                update(d, a, r, c, -1, 1);
                update(d, a, r, c, 1, -1);
                update(d, a, r, c, 1, 1);
            }
        }
    }

    // for (int r = 0; r < 8; ++r)
    // {
    //     for (int c = 0; c < 8; ++c)
    //         std::cout << a[r * 8 + c];
    //     std::cout <<std::endl;
    // }

    int answer = 64;
    for (int i = 0; i < 64; ++i)
        if (a[i])
            --answer;
    
    std::cout << answer << std::endl;

    return 0;
}