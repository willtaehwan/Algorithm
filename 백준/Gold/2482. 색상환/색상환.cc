#include <iostream>
#define MOD 1000000003
using namespace std;

int N, K;

int dp[1001][1001];

int main() {

	cin >> N >> K;
	
	for (int i = 0; i < N; i++) {
		dp[i][0] = 1;
		dp[i][1] = i;
	}
	
	for (int i = 2; i <= N; i++) {
		for (int j = 2; j <= K; j++) {
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MOD;
		}
	}

	cout << (dp[N - 1][K] + dp[N - 3][K - 1]) % MOD;

	return 0;
}