# 33. Списывание

| Условия             | Требование                         |
| ------------------- | ---------------------------------- | 
| Ограничение времени | 2 секунды                          |
| Ограничение памяти  | 256Mb                              |
| Ввод                | стандартный ввод или input.txt     |
| Вывод               | стандартный вывод или output.txt   |

Во время контрольной работы профессор Флойд заметил, что некоторые студенты обмениваются записками. Сначала он хотел поставить им всем двойки, но в тот день профессор был добрым, а потому решил разделить студентов на две группы: списывающих и дающих списывать, и поставить двойки только первым.

У профессора записаны все пары студентов, обменявшихся записками. Требуется определить, сможет ли он разделить студентов на две группы так, чтобы любой обмен записками осуществлялся от студента одной группы студенту другой группы.

## Формат ввода
В первой строке находятся два числа N и M — количество студентов и количество пар студентов, обменивающихся записками (1 ≤ N ≤ 10^2, 0 ≤ M ≤ N(N−1)/2).

Далее в M строках расположены описания пар студентов: два числа, соответствующие номерам студентов, обменивающихся записками (нумерация студентов идёт с 1). Каждая пара студентов перечислена не более одного раза.

## Формат вывода
Необходимо вывести ответ на задачу профессора Флойда. Если возможно разделить студентов на две группы - выведите YES; иначе выведите NO.

### Пример 1
#### Ввод:
```
3 2
1 2
2 3
```
#### Вывод:
```
YES
```
### Пример 2
#### Ввод:
```
3 3
1 2
2 3
1 3
```
#### Вывод:
```
NO
```