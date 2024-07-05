#include <iostream>

using namespace std;

int N, K;

int factorial(int a) {
	int result = 1;
	for (int i = 1; i <= a; i++) result *= i;
	return result;
}

int main() {

	cin >> N >> K;
	cout << factorial(N) / (factorial(N - K) * factorial(K));
	return 0;
}