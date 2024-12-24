#include <iostream>

using namespace std;

int M, Q;

int dp[21][200002];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> M;
	for (int i = 1; i <= M; i++) cin >> dp[0][i];
	
	for (int i = 1; i <= 20; i++) {
		for (int j = 0; j <= M; j++) {
			dp[i][j] = dp[i - 1][dp[i - 1][j]];
		}
	}

	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int n, x;
		cin >> n >> x;
		
		int cnt = 0;
		while (n != 0) {
			if (n & 1) x = dp[cnt][x];
			n = n >> 1;
			cnt++;
		}
		cout << x<<'\n';
	}

	return 0;
}