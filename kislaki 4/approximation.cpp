#include "approximation.h"
#include "gauss.h"
#include <vector>
#include <cmath>

using namespace std;

vector<double> approximate(vector<double> x, vector<double> y) {
    int m = 2;
    vector<vector<double>> left(m, vector<double>(m));
    vector<double> right(m);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            double element = 0;
            for (size_t t = 0; t < x.size(); t++) {
                element += pow(x[t], i + j);
            }
            left[i][j] = element;
        }
    }

    for (int i = 0; i < m; i++) {
        double element_right = 0;
        for (size_t j = 0; j < x.size(); j++) {
            element_right += y[j] * pow(x[j], i);
        }
        right[i] = element_right;
    }
    vector<double> solutions = gaussSolution(left, right, m);
    

    return solutions;
}