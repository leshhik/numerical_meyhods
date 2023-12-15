#include "Newtons Method.h"

int main()
{
    cout.precision(15);

    double x1 = 1, x2 = 1;
    int max_iter = 100;

    // Задание 2.1 - Метод Ньютона с вычислением J аналитическим методом
    solveNewtonsMethod(x1, x2, E1, E2, max_iter);

    // Задание 2.2 и 3 - Метод Ньютона с вычислением J численно конечно-разностным методом при M = 0.01, M = 0.05 и M = 0.1 
    vector<double> M = { 0.01, 0.05, 0.1 };

    // Прогоны вызова функции в цикле
    for (size_t i = 0; i < M.size(); i++)
    {
        double m = M[i];
        solveNewtonsMethod(x1, x2, E1, E2, max_iter, m);
    }
}