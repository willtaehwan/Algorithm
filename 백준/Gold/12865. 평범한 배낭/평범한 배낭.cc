#include <iostream>
#include <vector>
using namespace std;

int N, K;
int w, v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	vector<int> dp(K + 1, 0);
	int result = 0;

	for (int i = 0; i < N; i++) {
		cin >> w >> v;
		for (int j = K; j >= w; j--) {
			dp[j] = max(dp[j - w] + v, dp[j]);
		}
	}

	cout << dp[K];

	return 0;
}