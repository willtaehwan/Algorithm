#include <iostream>

using namespace std;

int N, K;
int w, v;

int dp[100001] = { 0, };

int main() {

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> w >> v;
		for (int j = K; j >= w; j--) {
			dp[j] = max(dp[j - w] + v, dp[j]);
		}
	}

	cout << dp[K];

	return 0;
}