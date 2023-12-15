#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

// Подынтегральная функция
double kubat_func(double x, double y) {
    return exp(x/2)/pow(x+1, 1/2);
}

double func(double x) {
    return (1 + x * x) / (1 + x * x * x);
}

// Определенный интеграл методом трапеций
double integrate_trapezoidal(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double result = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; ++i) {
        result += f(a + i * h);
    }
    result *= h;
    return result;
}

// Определенный интеграл методом Симпсона
double integrate_simpson(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double result = f(a) + f(b);
    for (int i = 1; i < n; i += 2) {
        result += 4 * f(a + i * h);
    }
    for (int i = 2; i < n - 1; i += 2) {
        result += 2 * f(a + i * h);
    }
    result *= h / 3;
    return result;
}

double kubat_simpson(double (*f)(double, double), double a, double b, double c, double d, int n, int m) {
    if (n % 2 != 0 || m % 2 != 0) {
        cerr << "Error: numbers of interval should be even. " << endl;
        return 0.0;
    }

    double hx = (b - a) / n;
    double hy = (d - c) / m;
    double result = 0.0;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            double x = a + i * hx;
            double y = c + j * hy;
            double z = f(x, y);

            if (i == 0 || i == n) {
                z *= 1.0;
            }
            else if (i % 2 == 1) {
                z *= 4.0;
            }
            else {
                z *= 2.0;
            }

            if (j == 0 || j == m) {
                z *= 1.0;
            }
            else if (j % 2 == 1) {
                z *= 4.0;
            }
            else {
                z *= 2.0;
            }

            result += z;
        }
    }

    result *= hx * hy / 9.0;
    return result;
}



int main() {
    SetConsoleOutputCP(CP_UTF8);
    double a = 3.0, b = 4.254;
    double a1 = 0.0, b1 = 2.0, c = 0.0, d = 1.0;
    double epsilon = 1e-5;
    int n = 10, m = 10;
    while (true) {
        double result_trapezoidal = integrate_trapezoidal(func, a, b, n);
        double result_simpson = integrate_simpson(func, a, b, n);
        double result_kubat_simpson = kubat_simpson(kubat_func, a1, b1, c, d, n, m);
        if ((result_trapezoidal - integrate_trapezoidal(func, a, b, 2 * n)) / 3 < epsilon) {
            break;
        }

        if ((result_simpson - integrate_simpson(func, a, b, 2 * n)) / 15 < epsilon) {
            break;
        }

        n *= 2;
        m *= 2;
    }
    cout << "Results of frist two intervals by my variant(6), cubaturny method - data was stollen from 31 variant" << endl;
    cout << "Result of trapesoid: " << integrate_trapezoidal(func, a, b, n) << endl;
    cout << "Result of method Sympson: " << integrate_simpson(func, a, b, n) << endl;
    cout << "Result of cubaturny method Sympson: " << kubat_simpson(kubat_func, a1, b1, c, d, n, m) << endl;

    return 0;
}
