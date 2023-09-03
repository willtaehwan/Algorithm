#include <iostream>

using namespace std;

int main() {

	int N;

	cin >> N;

	int M[101];
	for (int i = 0; i < N; i++) {
		cin >> M[i];
	}

	int cnt = 0;

	for (int i = 0; i < N; i++) {
		if (M[i] == 1) {
			continue;
		}
		int flag = 0;
		for (int j = 2; j < M[i]; j++) {
			if (M[i] % j == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			cnt++;
			
		}
	}
	cout << cnt;

	return 0;
}