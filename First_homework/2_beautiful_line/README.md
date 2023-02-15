# 2. Красивая строка

| Условия             | Требование                         |
| ------------------- | ---------------------------------- | 
| Ограничение времени | 1 секунда                          |
| Ограничение памяти  | 64Mb                               |
| Ввод                | стандартный ввод или input.txt     |
| Вывод               | стандартный вывод или output.txt   |

Красотой строки назовем максимальное число идущих подряд одинаковых букв. (красота строки abcaabdddettq равна 3)
Сделайте данную вам строку как можно более красивой, если вы можете сделать не более k операций замены символа.

## Формат ввода
В первой строке записано одно целое число k (0 ≤ k ≤ 109)
Во второй строке дана непустая строчка S (|S| ≤ 2 ⋅ 105). Строчка S состоит только из маленьких латинских букв.

## Формат вывода
Выведите одно число — максимально возможную красоту строчки, которую можно получить.

### Пример 1
#### Ввод:
```
2
abcaz
```
#### Вывод:
```
4
```
### Пример 2
#### Ввод:
```
2
helto
```
#### Вывод:
```
3
```