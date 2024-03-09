#include <iostream>
#include <cmath>
#include <iomanip>

double t_one_point(int L, double x1, double v1, double x2, double v2)
{
    double dv = fabs(v2 - v1);
    if (v1 == v2)
        return -1;
    else if (v1 > v2)
        return x1 > x2 ? ((L - x1 + x2) / dv) : ((x2 - x1) / dv);
    else //if (v2 > v1)
        return x1 < x2 ? ((L - x2 + x1) / dv) : ((x1 - x2) / dv);  
}

double t_two_point(int L, double x1, double v1, double x2, double v2)
{
    double tmin = std::numeric_limits<double>::infinity();
    double t0 = (0 - x1 - x2) / (v1 + v2);
    double t1 = (L - x1 - x2) / (v1 + v2);
    double t2 = (2 * L - x1 - x2) / (v1 + v2);
    if (t0 >= 0 && t0 < tmin)
        tmin = t0;
    if (t1 >= 0 && t1 < tmin)
        tmin = t1;
    if (t2 >= 0 && t2 < tmin)
        tmin = t2;
    
    return tmin == std::numeric_limits<double>::infinity() ? -1 : tmin;
}

double min_time(int L, int x1, int v1, int x2, int v2) 
{
    if (x1 == x2 || x1 + x2 == L)
        return 0;
    if (v1 == 0 && v2 == 0)
        return -1;

    double t_one = t_one_point(L, x1, v1, x2, v2);
    // std::cout << t_one << std::endl;

    double t_two= t_two_point(L, x1, v1, x2, v2);
    // std::cout << t_two << std::endl;

    if (t_one == -1)
        return t_two;
    else if (t_two == -1)
        return t_one;
    else
        return std::min(t_one, t_two);
}

int main() {
    int L, x1, v1, x2, v2;
    std::cin >> L >> x1 >> v1 >> x2 >> v2;
    
    double t = min_time(L, x1, v1, x2, v2);
    // double t = min_time(12, 8, 10, 5, 20);
    // double t = min_time(6, 3, 1, 1, 1);
    if (t < 0)
        std::cout << "no" << std::endl;
    else
        std::cout << "yes" << std::endl << std::setprecision(10) << t << std::endl;
    return 0;
}