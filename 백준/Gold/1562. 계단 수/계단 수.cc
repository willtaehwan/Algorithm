#include <iostream>
#define INF (int)1e9
using namespace std;

int N;
int dp[102][12] = {0, };

int DP(int s, int e) {
	s++; e++;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 11; j++) {
			dp[i][j] = 0;
		}
	}

	for (int i = s; i <= e; i++) dp[1][i] = 1;

	for (int i = 2; i <= N; i++) {
		for (int j = s; j <= e; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % INF;
			//if (j > s) dp[i][j] += dp[i - 1][j - 1];
			//if (j < e) dp[i][j] += dp[i - 1][j + 1];
			//dp[i][j] %= INF;
		}
	}
	int result = 0;
	for (int i = max(s,2); i <= e; i++) result = (result + dp[N][i]) % INF;
	return result;
}


int main() {

	cin >> N;
	cout << (DP(0, 9) - DP(0, 8) - DP(1, 9) + DP(1, 8) + INF) % INF;
	return 0;
}