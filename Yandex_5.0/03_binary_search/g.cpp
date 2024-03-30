/*
G. Новый офис плюса
Сервис Тындекс.Плюс так быстро растет, что для сотрудников и серверов потребовалось потребовалось построить новый офис.
Участок под застройку представляет из себя клетчатое поле n×m, часть клеток которого пригодна для строительства, а часть нет.
Новый офис должен выглядеть как знак "плюс"какого-то целого положительного размера k. Знак "плюс"размера k  — это такая клетчатая фигура, состоящая из пяти квадратов k×k клеток, при этом есть один центральный квадрат, а остальные четыре являются его соседями по стороне.
Новый офис должен быть как можно больше, поэтому необходимо найти максимальное k, такое что офис удастся разместить на участке под застройку.
Определите максимальное k. Гарантируется, что он можно построить офис хотя бы с k=1.

Формат ввода
В первой строке задано два целых числа n и m (1≤n,m≤2000) — длина и ширина участка под застройку.
В каждой из последующих n строк задана строка, состоящая из m символов, j-й символ в i-й строке равен #, если клетка с координатами (i,j) пригодна для строительства и . иначе.

Формат вывода
Выведите одно целое положительное число — максимально возможное k.
*/

#include <iostream>
#include <vector>
#include <fstream>

#define DEBUG 0

bool check_square(std::vector<std::vector<int>>& data, int r, int c, int s)
{
    if (data[r][c] >= s)
        return true;
    return false;
}

bool check(int mid, int n, int m, std::vector<std::vector<int>>& data)
{
    for (int r = 2 * mid; r <= n - mid; ++r)
        for (int c = 2 * mid; c <= m - mid; ++c)
        {
            if (check_square(data, r, c, mid) &&
                    check_square(data, r - mid, c, mid) &&
                    check_square(data, r + mid, c, mid) &&
                    check_square(data, r, c - mid, mid) &&
                    check_square(data, r, c + mid, mid))
                return true;
        }
    return false;
}

size_t binary_search(int n, int m, std::vector<std::vector<int>>& data) 
{
    size_t L = 1;
    size_t R = std::min(n, m) / 3;

    while (L < R)
    {
        size_t mid = (L + R + 1) / 2;
if (DEBUG) std::cout << mid << " " << L << " " << R << std::endl;

        if (check(mid, n, m, data))
            L = mid;
        else
            R = mid - 1;
if (DEBUG) std::cout << "\t" << mid << " " << L << " " << R << std::endl; 
    }
    return L;
}

int main()
{
    std::ifstream input("input.txt");
    int n, m;
    input >> n >> m;

    std::vector<std::vector<int>> data(n + 2, std::vector<int>(m + 2, 0)); // add false border
    {
        char tmp;
        for (int r = 1; r <= n; ++r)
            for (int c = 1; c <= m; ++c)
            {
                input >> tmp;
                if (tmp == '#')
                    data[r][c] = std::min(std::min(data[r - 1][c], data[r][c - 1]), data[r - 1][c - 1]) + 1;
            }
    }
    input.close();

    // for (int r = 1; r <= n; ++r)
    // {
    //     for (int c = 1; c <= m; ++c)
    //         std::cout << data[r][c] << " ";
    //     std::cout << std::endl;
    // }

    std::cout << binary_search(n, m, data) << std::endl;
    return 0;
}