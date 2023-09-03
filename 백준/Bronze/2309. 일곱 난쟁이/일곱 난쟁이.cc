#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int N[9] = { 0, };

	int sum = 0;

	for (int i = 0; i < 9; i++) {
		cin >> N[i];
		sum += N[i];
	}

	int flag = 0;
	for (int i = 0; i < 9; i++) {

		if (flag == 1) {
			break;
		}

		for (int j = 0; j < 9; j++) {
			if (i == j) {
				continue;
			}
			if (sum - N[i] - N[j] == 100) {
				N[i] = 0;
				N[j] = 0;
				flag = 1;
				break;
			}
		}
	}

	sort(N, N + 9);

	for (int i = 2; i < 9; i++) {
		cout << N[i] << endl;
	}

	return 0;
}