#include "prototypes.h"

int main()
{
    double* x;
    int n;

    cout << "Enter the number of equations: ";
    cin >> n;
    cout << endl;

    double** a = new double* [n];
    double* b = new double[n];

    for (int i = 0; i < n; i++)
    {
        a[i] = new double[n];
    }

    readMatrix(a, n);
    readVector(b, n);

    x = gaussSolution(a, b, n);

    if (x == nullptr)
    {
        // Error occurred during solution
        // Handle the error or exit the program
        return 1;
    }

    cout << "Solution:" << endl;
    printSolution(x, n);

    double* residual = new double[n];
    for (int i = 0; i < n; i++)
    {
        residual[i] = 0;
        for (int j = 0; j < n; j++)
        {
            residual[i] += a[i][j] * x[j];
        }
    }

    double norm = calculateNorm(residual, n);
    cout << "Norm = " << norm << endl;

    double error = calculateRelativeError(residual, x, n);
    cout << "Relative error = " << error << endl;

    for (int i = 0; i < n; i++)
    {
        delete[] a[i];
    }
    delete[] a;
    delete[] b;
    delete[] residual;
    delete[] x;

    return 0;
}
