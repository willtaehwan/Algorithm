#include <iostream>
#define MOD 10007;
using namespace std;

int N, K;

int DP[1001][1001] = { 0, };

int main() {

	cin >> N >> K;

	DP[0][0] = 1;

	for (int i = 1; i <=N; i++) {
		for (int j = 0; j <=K; j++) {
			if (j == 0) {
				DP[i][j] = 1;
				continue;
			}
			DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j]) % MOD;
		}
	}

	cout << DP[N][K];

	return 0;
}