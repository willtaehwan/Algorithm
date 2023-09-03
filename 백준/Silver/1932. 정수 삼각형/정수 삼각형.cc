#include <iostream>

using namespace std;

int map[501][501] = { 0, };
int DP[501][501] = { 0, };
int N;

int main() {

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> map[i][j];
		}
	}

	DP[0][0] = map[0][0];
	DP[1][0] = map[0][0] + map[1][0];
	DP[1][1] = map[0][0] + map[1][1];
	for (int i = 2; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == i) {
				DP[i][j] = DP[i - 1][j - 1] + map[i][j];
				continue;
			}

			if (j == 0) {
				DP[i][j] = DP[i - 1][0] + map[i][j];
				continue;
			}
			
			if (DP[i - 1][j - 1] < DP[i - 1][j]) {
				DP[i][j] = DP[i - 1][j] + map[i][j];
			}
			else {
				DP[i][j] = DP[i - 1][j - 1] + map[i][j];
			}
		}
	}
	int maxSum = 0;
	for (int i = 0; i < N; i++) {
		if (maxSum < DP[N - 1][i]) {
			maxSum = DP[N - 1][i];
		}
	}

	cout << maxSum;
	return 0;
}