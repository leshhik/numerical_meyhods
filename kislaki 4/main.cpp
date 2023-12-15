#include <iostream>
#include <vector>
#include "approximation.h"

using namespace std;

int main() {
	vector<double> x{19.1, 25, 30.1, 36.0, 40, 45.1, 50};
	vector<double> y{ 76.3, 77.8, 79.75, 80.80, 82.35, 83.90, 85 };
	vector<double> coeffs = approximate(x, y);
	cout << "coeffecients: \n";
	for (double i : coeffs) {
		cout << i << " ";
	}
	return 0;
}