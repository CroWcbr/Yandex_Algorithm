/*
J. Два прямоугольника
Недавно один известный художник-абстракционист произвел на свет новый шедевр — картину «Два черных непересекающихся прямоугольника». Картина представляет собой прямоугольник m× n, разбитый на квадраты 1× 1, некоторые из которых закрашены любимым цветом автора — черным. Федя — не любитель абстрактных картин, однако ему стало интересно, действительно ли на картине изображены два непересекающихся прямоугольника. Помогите ему это узнать. Прямоугольники не пересекаются в том смысле, что они не имеют общих клеток.

Формат ввода
Первая строка входного файла содержит числа m и n (1 ≤ m, n ≤ 200). Следующие m строк содержат описание рисунка. Каждая строка содержит ровно n символов. Символ «.» обозначает пустой квадрат, а символ «#» — закрашенный.

Формат вывода
Если рисунок можно представить как два непересекающихся прямоугольника, выведите в первой строке «YES», а в следующих m строках выведите рисунок в том же виде, в каком он задан во входном файле, заменив квадраты, соответствующие первому прямоугольнику на символ «a», а второму — на символ «b». Если решений несколько, выведите любое.
Если же этого сделать нельзя, выведите в выходной файл «NO».
*/

#include <iostream>
#include <vector>
#include <algorithm>

struct Point {
    int x;
    int y;
};

bool check_up_down(std::vector<std::vector<char>>& data, Point up_left, Point down_right, int rect)
{
    std::vector<std::vector<char>> tmp(data);
    tmp[up_left.y][up_left.x] = 'a';
    tmp[down_right.y][down_right.x] = 'b';

    int up_right;
    for (up_right = up_left.x; tmp[up_left.y][up_right + 1] != '.'; ++up_right)
        ;
    while ((tmp[up_left.y][up_left.x] == '#' || tmp[up_left.y][up_left.x] == 'a') && 
            tmp[up_left.y][up_left.x - 1] != '#' && 
            tmp[up_left.y][up_right + 1] != '#' &&
            (tmp[up_left.y][up_right] == '#' || tmp[up_left.y][up_right] == 'a'))
    {
        for (int i = up_left.x; i <= up_right; ++i)
        {
            if (tmp[up_left.y][i] != '#' && tmp[up_left.y][i] != 'a')
            {
                return false;
            }
            tmp[up_left.y][i] = 'a';
            --rect;
        }
        ++up_left.y;
    }

    int down_left;
    for (down_left = down_right.x; tmp[down_right.y][down_left - 1] != '.'; --down_left) 
        ;
    while ((tmp[down_right.y][down_right.x] == '#' || tmp[down_right.y][down_right.x] == 'b') &&
            tmp[down_right.y][down_right.x + 1] != '#' &&
            tmp[down_right.y][down_left - 1] != '#' &&
            (tmp[down_right.y][down_left] == '#' || tmp[down_right.y][down_left] == 'b'))
    {
        for (int i = down_left; i <= down_right.x; ++i)
        {
            if (tmp[down_right.y][i] != '#' && tmp[down_right.y][i] != 'b')
            {
                return false;
            }
            tmp[down_right.y][i] = 'b';
            --rect;
        }
        --down_right.y;
    }

    if (rect != 0)
    {
        return false;
    }

    data = std::move(tmp);
    return true;
}

bool check_left_right(std::vector<std::vector<char>>& data, Point left_up, Point right_down, int rect)
{
    std::vector<std::vector<char>> tmp(data);
    tmp[left_up.y][left_up.x] = 'a';
    tmp[right_down.y][right_down.x] = 'b';

    int left_down;
    for (left_down = left_up.y; tmp[left_down + 1][left_up.x] != '.'; ++left_down)
        ;
    while ((tmp[left_up.y][left_up.x] == '#' || tmp[left_up.y][left_up.x] == 'a') &&
            tmp[left_up.y - 1][left_up.x] != '#' &&
            tmp[left_down + 1][left_up.x] != '#' &&
            (tmp[left_down][left_up.x] == '#' || tmp[left_down][left_up.x] == 'a'))
    {

        for (int i = left_up.y; i <= left_down; ++i)
        {

            if (tmp[i][left_up.x] != '#' && tmp[i][left_up.x] != 'a')
            {
                return false;
            }
            tmp[i][left_up.x] = 'a';
            --rect;
        }
        ++left_up.x;
    }

    int right_up;
    for (right_up = right_down.y; tmp[right_up - 1][right_down.x] != '.'; --right_up)
        ;
    while ((tmp[right_up][right_down.x] == '#' || tmp[right_up][right_down.x] == 'b') &&
            tmp[right_up - 1][right_down.x] != '#' &&
            tmp[right_down.y + 1][right_down.x] != '#' &&
            (tmp[right_up][right_down.x] == '#' || tmp[right_up][right_down.x] == 'b'))
    {
        for (int i = right_up; i <= right_down.y; ++i)
        {
            if (tmp[i][right_down.x] != '#' && tmp[i][right_down.x] != 'b')
            {
                return false;
            }
            tmp[i][right_down.x] = 'b';
            --rect;
        }
        --right_down.x;
    }
    if (rect != 0)
    {
        return false;
    }
    data = std::move(tmp);
    return true;
}

int main()
{
	int row, col;
    std::cin >> row >> col;

    row += 2; // border
    col += 2; // border
    
    std::vector<std::vector<char>> data(row, std::vector<char>(col, '.'));
    int rect = 0;
    int left, right, up, down;
    left = col;
    right = -1;
    up = row;
    down = -1;
    for (int y = 1; y < row - 1; ++y)
    {
        for (int x = 1; x < col - 1; ++x)
        {
            char tmp;
            std::cin >> tmp;
            
            if (tmp == '#')
            {
                data[y][x] = tmp;
                if (left > x)
                    left = x;
                if (right < x)
                    right = x;
                if (up > y)
                    up = y;
                if (down < y)
                    down = y;

                rect++;
            }
        }
    }

    if (rect <= 1)
    {
        std::cout << "NO" << std::endl;
        return 0;
    }
    
    Point up_left, down_right, left_up, right_down;
    {
        int i;
        for (i = 0; data[up][i] != '#'; ++i) ;
        up_left = {i, up};
        for (i = 0; data[i][left] != '#'; ++i) ;
        left_up = {left, i};
        for (i = col - 1; data[down][i] != '#'; --i) ;
        down_right = {i, down};
        for (i = row - 1; data[i][right] != '#'; --i) ;
        right_down = {right, i};
    }
    if (check_up_down(data, up_left, down_right, rect) || check_left_right(data, left_up, right_down, rect))
    {
        std::cout << "YES" << std::endl;
        for (int y = 1; y < row - 1; ++y)
        {
            for (int x = 1; x < col - 1; ++x)
                std::cout << data[y][x];
            std::cout << std::endl;
        }
    }
    else
        std::cout << "NO" << std::endl;

    return 0;
}