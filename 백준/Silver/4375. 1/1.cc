#include <iostream>
using namespace std;

int main() {

	int N;

	while (cin >> N) {
		int min;

		int result = 1;
		int sum = 0;
		for (int i = 0; i < 100001; i++) {

			sum += result % N;

			if (sum % N == 0) {
				min = i;
				break;
			}
			else {
				result %= N;
				result *= 10;
			}
		}

		cout << min + 1<<endl;
	}
	

	return 0;
}