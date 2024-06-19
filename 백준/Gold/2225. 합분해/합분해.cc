#include <iostream>

using namespace std;

// DP[K][N] = DP[K-1][0] + DP[K-1][1] + ... + DP[K-1][N]
// K >= 1
// K가 1이면 DP[1][N] = 1
// DP[K][0] = 1, DP[K][1] = K 
// DP[2][20] = DP[1][0] ~ DP[1][20] => 

int DP[201][201] = { 0, };

int dp(int n, int k) {

	if (k == 1) return 1;

	if (DP[k][n] != 0) return DP[k][n];

	for (int i = 0; i <= n; i++) {
		DP[k][n] += dp(i, k - 1);
		DP[k][n] = DP[k][n] % 1000000000;
	}

	return DP[k][n];
}

int main() {

	int N, K;

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		DP[1][i] = 1;
	}

	cout << dp(N, K);


	return 0;
}