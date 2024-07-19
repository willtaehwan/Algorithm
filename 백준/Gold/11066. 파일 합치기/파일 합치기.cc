#include <iostream>
#include <algorithm>
using namespace std;

int dp[501][501] = { 0, };
int sum[501] = { 0, };

int main() {

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		int K;
		cin >> K;

		sum[0] = 0;

		for (int i = 1; i <= K; i++) {
			int now;
			cin >> now;
			sum[i] = sum[i - 1] + now;
		}

		for (int k = 1; k < K; k++) {
			int i = 1;
			int j = k + 1;
			for (int n = 0; n < K - k; n++) { 
				dp[i][j] = 1e9;
				for (int m = j-k; m <= j-1; m++) {
					dp[i][j] = min(dp[i][j], dp[i][m] + dp[m + 1][j] + sum[j] - sum[i - 1]);
				}
				i++;
				j++;
			}
		}

		cout << dp[1][K] << '\n';
	}


}