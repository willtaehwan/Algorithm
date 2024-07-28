#include <iostream>

using namespace std;

int N;

int main() {

	cin >> N;
	int a = 1;
	int sum = 0;
	while (a * a <= N) {
		if (N % a == 0) {
			sum++;
			if (a * a != N) sum++;
		}
		a++;
	}

	cout << sum;

	return 0;
}