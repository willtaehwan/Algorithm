#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

int main() {
	double a;
	cin >> a;

	cout.precision(12);
	cout << 2 * M_PI * sqrt(a / M_PI);

	return 0;
}