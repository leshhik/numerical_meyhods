#include "Header.h"
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

    //printMatrix(a, b, n);

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
    double error = abs(max1 - max2) / abs(max1);

    cout << "Relative error = " << error << endl;

    for (int i = 0; i < n; i++)
    {
        delete[] a[i];
    }
    delete[] a;
    delete[] b;

    return 0;
}
