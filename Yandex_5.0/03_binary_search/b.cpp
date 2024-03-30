/*
B. Одномерный морской бой
Поле в игре в одномерный морской бой имеет размеры 1×n. Ваша задача — найти такое максимальное k, что на поле можно расставить один корабль размера 1×k, два корабля размера 1×(k−1),…,k кораблей размера 1×1, причем корабли, как и в обычном морском бое, не должны касаться друг друга и пересекаться.

Формат ввода
В единственной строке входных данных дано число n — количество клеток поля (0≤n≤10^18).

Формат вывода
Выведите единственное число — такое максимальное k, что можно расставить корабли, как описано в условии.
*/

#include <iostream>

bool check(size_t k, size_t n)
{
    size_t pole = 0;
    size_t num = 0;
    for(size_t ship_size = 1, num_ship = k; num_ship > 0; ++ship_size, --num_ship)
    {
        pole += ship_size * num_ship;
        num += num_ship;
        if (pole > n - num + 1)
            return false;
    }
    return true;
}

size_t binary_search(size_t n)
{
    size_t left = 0;
    size_t right = n / 2 + 1;

    while (left < right)
    {
        size_t mid = (left + right + 1) / 2;
        if (check(mid, n))
            left = mid;
        else
            right = mid - 1;
    }
    return left;
}

int main()
{
    size_t n;
    std::cin >> n;

    std::cout << binary_search(n) << std::endl;
    return 0;
}