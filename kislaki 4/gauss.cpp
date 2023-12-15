#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void readMatrix(vector<vector<double>>& matrix, int size)
{
    // Заполняем матрицу значениями
    matrix = { {1, 2, 3},
               {4, 5, 6},
               {7, 8, 9} };
}

void readVector(vector<double>& vector, int size)
{
    // Задаем константные значения вектора
    vector = { 1.0, 2.0, 0.0 };
}

void printMatrix(const vector<vector<double>>& matrix, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void printMatrixWithVector(const vector<vector<double>>& matrix, const vector<double>& vector, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "| " << vector[i] << endl;
    }
    cout << endl;
}

void normalizeRow(vector<double>& row, double divisor, int size)
{
    for (int j = 0; j < size; j++) {
        row[j] /= divisor;
    }
}

vector<double> gaussSolution(vector<vector<double>> matrix, vector<double> vector, int size)
{
    const double eps = 0.00000000001; // Точность

    // Прямой ход
    for (int k = 0; k < size; k++) {
        // Поиск строки с максимальным элементом в текущем столбце
        int maxRow = k;
        for (int i = k + 1; i < size; i++) {
            if (abs(matrix[i][k]) > abs(matrix[maxRow][k])) {
                maxRow = i;
            }
        }

        if (abs(matrix[maxRow][k]) < eps) {
            cout << "The solution cannot be obtained due to the zero column " << maxRow << " of the matrix A" << endl;
            return std::vector<double>();
        }

        // Перестановка строк
        for (int j = k; j < size; j++) {
            swap(matrix[k][j], matrix[maxRow][j]);
        }
        swap(vector[k], vector[maxRow]);

        // Нормализация уравнений
        double divisor = matrix[k][k];
        normalizeRow(matrix[k], divisor, size);
        vector[k] /= divisor;

        for (int i = k + 1; i < size; i++) {
            double factor = matrix[i][k];
            for (int j = k; j < size; j++) {
                matrix[i][j] -= factor * matrix[k][j];
            }
            vector[i] -= factor * vector[k];
        }
    }

    // Обратный ход
    std::vector<double> solution(size);
    for (int i = size - 1; i >= 0; i--) {
        double sum = 0.0;
        for (int j = i + 1; j < size; j++) {
            sum += matrix[i][j] * solution[j];
        }
        solution[i] = (vector[i] - sum) / matrix[i][i];
    }

    return solution;
}

double calculateRelativeError(const vector<double>& residual, const vector<double>& solution, int size)
{
    double maxResidual = abs(residual[0]);
    double maxSolution = abs(solution[0]);

    for (int i = 1; i < size; i++) {
        if (std::abs(residual[i]) > maxResidual) {
            maxResidual = abs(residual[i]);
        }

        if (abs(solution[i]) > maxSolution) {
            maxSolution = abs(solution[i]);
        }
    }

    double error = abs(maxResidual - maxSolution) / max(maxResidual, maxSolution);
    return error;
}

void printSolution(const vector<double>& solution, int size)
{
    for (int i = 0; i < size; i++) {
        cout << "x" << i + 1 << " = " << solution[i] << endl;
    }
}