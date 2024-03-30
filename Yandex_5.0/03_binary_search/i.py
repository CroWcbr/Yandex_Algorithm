'''
I. Лапта
При игре в лапту одна команда ловит мяч и пытается осалить им бегущего. Игрок другой команды должен, перед тем как бежать, ударить мяч в поле. Известно, на какое максимальное расстояние он может ударить, а также скорости и начальные координаты игроков другой команды. Требуется выбрать направление и силу удара так, чтобы минимальное время, которое потребуется другой команде, чтобы поднять мяч с земли, было наибольшим. (Пока мяч летит, игроки стоят на местах).

Формат ввода
В первой строке записаны два числа: D — максимальное расстояние удара и N — количество соперников на поле (D и N натуральные числа, D ≤ 1000, N ≤ 200). В следующих N строках записаны по три числа – начальные координаты xi и yi и максимальная скорость vi соответствующего игрока (скорости и координаты — целые числа, –1000 ≤ xi ≤ 1000, 0 ≤ yi ≤ 1000, 0 < vi ≤ 1000), никакие два игрока не находятся изначально в одной точке. Игрок, бьющий мяч, находится в точке с координатами (0, 0). Мяч выбивается в точку с неотрицательной ординатой (y ≥ 0).

Формат вывода
В выходной файл выведите сначала время, которое потребуется игрокам, чтобы добежать до мяча, а затем координаты точки, в которую нужно выбить мяч. Если таких точек несколько, выведите координаты любой из них. Время и координаты нужно вывести с точностью 10^–3.
'''

# !!!!не мое решение!!!!, решение с яндекс контекста

def pointcircle(x0, y0, r0, xp, yp):
    return (xp - x0)**2 + (yp - y0)**2 - r0**2 < 0.000001

def checkrect(xll, yll, xru, yru, time):
    if not pointcircle(0, 0, d, xll, yll) and \
        not pointcircle(0, 0, d, xll, yru) and \
        not pointcircle(0, 0, d, xru, yll) and \
        not pointcircle(0, 0, d, xru, yru):
        return (False, (0,0))
    if xru - xll < 0.000001:
        return (True, ((xll + xru) / 2, (yll + yru) / 2))
    for i in range(n):
        if pointcircle(x[i], y[i], v[i] * time, xll, yll) and \
            pointcircle(x[i], y[i], v[i] * time, xll, yru) and \
            pointcircle(x[i], y[i], v[i] * time, xru, yll) and \
            pointcircle(x[i], y[i], v[i] * time, xru, yru):
            return (False, (0,0))
    xs = [xll, (xll + xru) / 2, xru]
    ys = [yll, (yll + yru) / 2, yru]
    for i in range(2):
        for j in range(2):
            quarter = checkrect(xs[i], ys[j], xs[i + 1], ys[j + 1], time)
            if quarter[0]:
                return quarter
    return (False, (0,0))

def check(time):
    return checkrect(-d, 0, d, d, time)

with open("input.txt", "r") as file:
    d, n = map(int, file.readline().split())

    x = [0] * n
    y = [0] * n
    v = [0] * n
    for i in range(n):
        x[i], y[i], v[i] = map(int, file.readline().split())

l = 0
r = 4 * d
while r - l > 0.000001:
    m = (l + r) / 2
    if check(m)[0]:
        l = m
    else:
        r = m

now = check(l)
print(l)
print(*now[1])