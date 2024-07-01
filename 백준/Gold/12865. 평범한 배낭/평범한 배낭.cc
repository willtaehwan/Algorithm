#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int w, v;

int DP[101][100010] = { 0, };

int main() {

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> w >> v;
		for (int j = 1; j <= K; j++) {
			if (j - w >= 0) DP[i][j] = max(DP[i - 1][j - w] + v, DP[i-1][j]);
			else DP[i][j] = DP[i - 1][j];
		}
	}

	cout << DP[N][K];

	return 0;
}