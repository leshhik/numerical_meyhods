#include "Header1.h"

double* metodGauss(double** a, double* b, int n)
{
    double* x, max;
    int k, index;
    const double eps = 0.00001;  // ��������

    x = new double[n];
    k = 0;

    while (k < n) // ����� ������ � ������������ a[i][k]
    {
        max = abs(a[k][k]);
        index = k;

        for (int i = k + 1; i < n; i++)
        {
            if (abs(a[i][k]) > max)
            {
                max = abs(a[i][k]);
                index = i;
            }
        }

        if (max < eps) // �������� �� ������� �������
        {
            cout << "The solution cannot be obtained due to the zero column ";
            cout << index << " of the matrix A" << endl;
            return 0;
        }

        for (int j = 0; j < n; j++) // ������������ �����
        {
            double value = a[k][j];
            a[k][j] = a[index][j];
            a[index][j] = value;
        }

        double value = b[k];
        b[k] = b[index];
        b[index] = value;

        // ������������ ���������
        for (int i = k; i < n; i++)
        {
            double value = a[i][k];

            if (abs(value) < eps) // �� ����������� ��� �������� ������������
            {
                continue;
            }

            for (int j = 0; j < n; j++)
            {
                a[i][j] = a[i][j] / value;
            }
            b[i] = b[i] / value;

            if (i == k) // ��� ���� ����� ��������� �� ���������� ���� �� ����
            {
                continue;
            }

            for (int j = 0; j < n; j++)
            {
                a[i][j] = a[i][j] - a[k][j];
            }
            b[i] = b[i] - b[k];
        }

        k++;
    }

    for (k = n - 1; k >= 0; k--) // �������� ���
    {
        x[k] = b[k];

        for (int i = 0; i < k; i++)
        {
            b[i] = b[i] - a[i][k] * x[k];
        }
    }

    return x;
}

double* metodGauss2(double** a, double* F, int n)
{
    double* x, max;
    int k, index;
    const double eps = 0.00001;  // ��������

    x = new double[n];
    k = 0;

    while (k < n) // ����� ������ � ������������ a[i][k]
    {
        max = abs(a[k][k]);
        index = k;

        for (int i = k + 1; i < n; i++)
        {
            if (abs(a[i][k]) > max)
            {
                max = abs(a[i][k]);
                index = i;
            }
        }

        if (max < eps) // �������� �� ������� �������
        {
            cout << "The solution cannot be obtained due to the zero column ";
            cout << index << " of the matrix A" << endl;
            return 0;
        }

        for (int j = 0; j < n; j++) // ������������ �����
        {
            double value = a[k][j];
            a[k][j] = a[index][j];
            a[index][j] = value;
        }

        double value = F[k];
        F[k] = F[index];
        F[index] = value;

        // ������������ ���������
        for (int i = k; i < n; i++)
        {
            double value = a[i][k];

            if (abs(value) < eps) // �� ����������� ��� �������� ������������
            {
                continue;
            }

            for (int j = 0; j < n; j++)
            {
                a[i][j] = a[i][j] / value;
            }
            F[i] = F[i] / value;

            if (i == k) // ��� ���� ����� ��������� �� ���������� ���� �� ����
            {
                continue;
            }

            for (int j = 0; j < n; j++)
            {
                a[i][j] = a[i][j] - a[k][j];
            }
            F[i] = F[i] - F[k];
        }

        k++;
    }

    for (k = n - 1; k >= 0; k--) // �������� ���
    {
        x[k] = F[k];

        for (int i = 0; i < k; i++)
        {
            F[i] = F[i] - a[i][k] * x[k];
        }
    }

    return x;
}
