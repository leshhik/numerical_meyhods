#include "Header1.h"

//double* metodGauss(double** a, double* b, int n)
//{
//    double* x, max;
//    int k, index;
//    const double eps = 0.00001;  // Точность
//
//    x = new double[n];
//    k = 0;
//
//    while (k < n) // Поиск строки с максимальным a[i][k]
//    {
//        max = abs(a[k][k]);
//        index = k;
//
//        for (int i = k + 1; i < n; i++)
//        {
//            if (abs(a[i][k]) > max)
//            {
//                max = abs(a[i][k]);
//                index = i;
//            }
//        }
//
//        if (max < eps) // Проверка на нулевой столбец
//        {
//            cout << "The solution cannot be obtained due to the zero column ";
//            cout << index << " of the matrix A" << endl;
//            return 0;
//        }
//
//        for (int j = 0; j < n; j++) // Перестановка строк
//        {
//            double value = a[k][j];
//            a[k][j] = a[index][j]; 
//            a[index][j] = value;
//        }
//
//        double value = b[k];
//        b[k] = b[index];
//        b[index] = value;
//
//        // Нормализация уравнений
//        for (int i = k; i < n; i++)
//        {
//            double value = a[i][k];
//
//            if (abs(value) < eps) // Не выполняется для нулевого коэффициента
//            {
//                continue;
//            }
//
//            for (int j = 0; j < n; j++)
//            {
//                a[i][j] = a[i][j] / value;
//            }
//            b[i] = b[i] / value;
//
//            if (i == k) // Для того чтобы уравнение не вычиталось само из себя
//            {
//                continue;
//            }
//
//            for (int j = 0; j < n; j++)
//            {
//                a[i][j] = a[i][j] - a[k][j];
//            }
//            b[i] = b[i] - b[k];
//        }
//
//        k++;
//    }
//
//    for (k = n - 1; k >= 0; k--) // Обратный ход
//    {
//        x[k] = b[k];
//
//        for (int i = 0; i < k; i++)
//        {
//            b[i] = b[i] - a[i][k] * x[k];
//        }
//    }
//
//    return x;
//}
//
//double* metodGauss2(double** a, double* F, int n)
//{
//    double* x, max;
//    int k, index;
//    const double eps = 0.00001;  // Точность
//
//    x = new double[n];
//    k = 0;
//
//    while (k < n) // Поиск строки с максимальным a[i][k]
//    {
//        max = abs(a[k][k]);
//        index = k;
//
//        for (int i = k + 1; i < n; i++)
//        {
//            if (abs(a[i][k]) > max)
//            {
//                max = abs(a[i][k]);
//                index = i;
//            }
//        }
//
//        if (max < eps) // Проверка на нулевой столбец
//        {
//            cout << "The solution cannot be obtained due to the zero column ";
//            cout << index << " of the matrix A" << endl;
//            return 0;
//        }
//
//        for (int j = 0; j < n; j++) // Перестановка строк
//        {
//            double value = a[k][j];
//            a[k][j] = a[index][j];
//            a[index][j] = value;
//        }
//
//        double value = F[k];
//        F[k] = F[index];
//        F[index] = value;
//
//        // Нормализация уравнений
//        for (int i = k; i < n; i++)
//        {
//            double value = a[i][k];
//
//            if (abs(value) < eps) // Не выполняется для нулевого коэффициента
//            {
//                continue;
//            }
//
//            for (int j = 0; j < n; j++)
//            {
//                a[i][j] = a[i][j] / value;
//            }
//            F[i] = F[i] / value;
//
//            if (i == k) // Для того чтобы уравнение не вычиталось само из себя
//            {
//                continue;
//            }
//
//            for (int j = 0; j < n; j++)
//            {
//                a[i][j] = a[i][j] - a[k][j];
//            }
//            F[i] = F[i] - F[k];
//        }
//
//        k++;
//    }
//
//    for (k = n - 1; k >= 0; k--) // Обратный ход
//    {
//        x[k] = F[k];
//
//        for (int i = 0; i < k; i++)
//        {
//            F[i] = F[i] - a[i][k] * x[k];
//        }
//    }
//
//    return x;
//}

int main()
{
    double* x;
    int n;

    cout << "Enter the number of equations: "; // Количество уравнений
    cin >> n;
    cout << endl;

    double** a = new double* [n];
    double* b = new double[n];
    double* F = new double[n];

    for (int i = 0; i < n; i++)
    {
        a[i] = new double[n];
        for (int j = 0; j < n; j++)
        {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "b[" << i << "] = ";
        cin >> b[i];
    }
    cout << endl;


    double** aCopy = new double* [n];

    for (int i = 0; i < n; i++)
    {
        aCopy[i] = new double[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            aCopy[i][j] = a[i][j];
        }
    }

    double* bCopy = new double[n];

    for (int i = 0; i < n; i++)
    {
        bCopy[i] = b[i];
    }


    x = metodGauss(a, b, n);

    for (int i = 0; i < n; i++)
    {
        cout << "x[" << i << "] = " << x[i] << endl;
    }
    cout << endl;


    // Вектор невязки

    for (int i = 0; i < n; i++)
    {
        F[i] = 0;
        for (int j = 0; j < n; j++)
        {
            F[i] += aCopy[i][j] * x[j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        F[i] -= bCopy[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << "F[" << i << "] = " << F[i] << endl;
    }
    cout << endl;


    // Норма

    int k = 0;
    double norm = abs(F[k]);

    for (int i = k + 1; i < n; i++)
    {
        if (abs(F[i]) > norm)
        {
            norm = abs(F[i]);
        }
    }
    cout << "Norm = " << norm << endl;
    cout << endl;


    for (int i = 0; i < n; i++)
    {
        F[i] = 0;
        for (int j = 0; j < n; j++)
            F[i] += a[i][j] * x[j];

    }

    x = metodGauss2(a, F, n);

    double max1 = abs(F[k]);

    for (int i = k + 1; i < n; i++)
    {
        if (abs(F[i]) > max1)
        {
            max1 = abs(F[i]);

        }
    }

    double max2 = abs(x[k]);
    for (int i = k + 1; i < n; i++)
    {
        if (abs(x[i]) > max2)
        {
            max2 = abs(x[i]);

        }
    }

    // Относительная погрешность

    double error = abs(max1 - max2) / abs(max2);

    cout << "Relative error = " << error;

    for (int i = 0; i < n; i++)
    {
        delete[] a[i];
    }
    delete[] a;
    delete[] b;

    return 0;
}
