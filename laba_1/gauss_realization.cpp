#include "prototypes.h"

void readMatrix(double** matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }
        cout << endl;
    }
}
void normalizeRow(double* row, double divisor, int size)
{
    for (int j = 0; j < size; j++)
    {
        row[j] /= divisor;
    }
}
void readVector(double* vector, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "b[" << i << "] = ";
        cin >> vector[i];
    }
    cout << endl;
}

void printMatrix(double** matrix, double* vector, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "| " << vector[i] << endl;
    }
    cout << endl;
}

#include "prototypes.h"

double* gaussSolution(double** matrix, double* vector, int size)
{
    const double eps = 0.00000000001; // Точность

    // Прямой ход
    for (int k = 0; k < size; k++)
    {
        // Поиск строки с максимальным элементом в текущем столбце
        int maxRow = k;
        for (int i = k + 1; i < size; i++)
        {
            if (abs(matrix[i][k]) > abs(matrix[maxRow][k]))
            {
                maxRow = i;
            }
        }

        if (abs(matrix[maxRow][k]) < eps)
        {
            cout << "The solution cannot be obtained due to the zero column " << maxRow << " of the matrix A" << endl;
            return nullptr;
        }

        // Перестановка строк
        for (int j = k; j < size; j++)
        {
            swap(matrix[k][j], matrix[maxRow][j]);
        }
        swap(vector[k], vector[maxRow]);

        // Нормализация уравнений
        double divisor = matrix[k][k];
        normalizeRow(matrix[k], divisor, size);
        vector[k] /= divisor;

        for (int i = k + 1; i < size; i++)
        {
            double factor = matrix[i][k];
            for (int j = k; j < size; j++)
            {
                matrix[i][j] -= factor * matrix[k][j];
            }
            vector[i] -= factor * vector[k];
        }

        cout << "Iteration " << k + 1 << ":" << endl;
        printMatrix(matrix, vector, size);
    }

    // Обратный ход
    double* solution = new double[size];
    for (int i = size - 1; i >= 0; i--)
    {
        double sum = 0.0;
        for (int j = i + 1; j < size; j++)
        {
            sum += matrix[i][j] * solution[j];
        }
        solution[i] = (vector[i] - sum) / matrix[i][i];
    }

    // Calculate and print the residual vector
    printResidualVector(matrix, vector, solution, size);

    return solution;
}

double calculateRelativeError(double* residual, double* solution, int size)
{
    double maxResidual = abs(residual[0]);
    double maxSolution = abs(solution[0]);

    for (int i = 1; i < size; i++)
    {
        if (abs(residual[i]) > maxResidual)
        {
            maxResidual = abs(residual[i]);
        }

        if (abs(solution[i]) > maxSolution)
        {
            maxSolution = abs(solution[i]);
        }
    }

    double error = abs(maxResidual - maxSolution) / max(maxResidual, maxSolution);
    return error;
}


void printSolution(double* solution, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "x[" << i << "] = " << solution[i] << endl;
    }
    cout << endl;
}

void printResidualVector(double** matrix, double* vector, double* solution, int size)
{
    double* residual = new double[size];

    for (int i = 0; i < size; i++)
    {
        residual[i] = 0;
        for (int j = 0; j < size; j++)
        {
            residual[i] += matrix[i][j] * solution[j];
        }
        cout << "F[" << i << "] = " << residual[i] - vector[i] << endl;
    }
    cout << endl;

    delete [] residual;
}

double calculateNorm(double* vector, int size)
{
    double norm = abs(vector[0]);

    for (int i = 1; i < size; i++)
    {
        if (abs(vector[i]) > norm)
        {
            norm = abs(vector[i]);
        }
    }

    return norm;
}
