﻿#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double S(const double x, const double eps, int& n, double s);
double A(const double x, const int n, double a);

int main()
{
    double xp, xk, x, dx, eps, s = 0;
    int n = 0;
    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;
    cout << fixed;
    cout << "-----------------------------------------------------------" << endl;
    cout << "|" << setw(10) << "x" << " |"
        << setw(15) << "cos(x)" << " |"
        << setw(15) << "S" << " |"
        << setw(10) << "n" << " |"
        << endl;
    cout << "-----------------------------------------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        s = S(x, eps, n, s);
        cout << "|" << setw(10) << setprecision(2) << x << " |"
            << setw(15) << setprecision(10) << cos(x) << " |"
            << setw(15) << setprecision(10) << s << " |"
            << setw(10) << n << " |"
            << endl;
        x += dx;
    }
    cout << "-----------------------------------------------------------" << endl;
    return 0;
}

double S(const double x, const double eps, int& n, double s)
{
    n = 0;
    double a = 1;
    s = a;
    do {
        n++;
        a = A(x, n, a);
        s += a;
    } while (abs(a) >= eps);
    return s;
}

double A(const double x, const int n, double a)
{
    double R = -x * x / ((2 * n - 1) * (2 * n));
    a *= R;
    return a;
}
