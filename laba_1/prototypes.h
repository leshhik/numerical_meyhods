#include <iostream>
#include <cmath>

using namespace std;

void readMatrix(double** matrix, int size);
void readVector(double* vector, int size);
void printMatrix(double** matrix, double* vector, int size);
double* gaussSolution(double** matrix, double* vector, int size);
double calculateRelativeError(double* residual, double* solution, int size);
void printSolution(double* solution, int size);
void printResidualVector(double** matrix, double* vector, double* solution, int size);
double calculateNorm(double* vector, int size);
void normalizeRow(double* row, double divisor, int size);
