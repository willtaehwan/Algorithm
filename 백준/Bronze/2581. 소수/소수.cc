#include <iostream>
using namespace std;

int main() {

	int M, N;

	cin >> M >> N;
	int result = 0;
	int min_result = 10001;
	int min_f = 0;
	for (int i = M; i <= N; i++) {
		if (i == 1) {
			continue;
		}

		int flag = 0;
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			result += i;
			if (min_f == 0) {
				min_result = i;
				min_f = 1;
			}
		}
	}
	if (min_result == 10001) {
		cout << -1;
	}
	else {
		cout << result << endl;
		cout << min_result;
	}
	

	return 0;
}