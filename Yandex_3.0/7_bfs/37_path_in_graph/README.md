# 37. Путь в графе

| Условия             | Требование                         |
| ------------------- | ---------------------------------- | 
| Ограничение времени | 1 секунды                          |
| Ограничение памяти  | 64Mb                               |
| Ввод                | стандартный ввод или input.txt     |
| Вывод               | стандартный вывод или output.txt   |

В неориентированном графе требуется найти минимальный путь между двумя вершинами.

## Формат ввода
Первым на вход поступает число N – количество вершин в графе (1 ≤ N ≤ 100). Затем записана матрица смежности (0 обозначает отсутствие ребра, 1 – наличие ребра). Далее задаются номера двух вершин – начальной и конечной.

## Формат вывода
Выведите сначала L – длину кратчайшего пути (количество ребер, которые нужно пройти), а потом сам путь. Если путь имеет длину 0, то его выводить не нужно, достаточно вывести длину.

Необходимо вывести путь (номера всех вершин в правильном порядке). Если пути нет, нужно вывести -1.

### Пример 1
#### Ввод:
```
10
0 1 0 0 0 0 0 0 0 0
1 0 0 1 1 0 1 0 0 0
0 0 0 0 1 0 0 0 1 0
0 1 0 0 0 0 1 0 0 0
0 1 1 0 0 0 0 0 0 1
0 0 0 0 0 0 1 0 0 1
0 1 0 1 0 1 0 0 0 0
0 0 0 0 0 0 0 0 1 0
0 0 1 0 0 0 0 1 0 0
0 0 0 0 1 1 0 0 0 0
5 4
```
#### Вывод:
```
2
5 2 4
```