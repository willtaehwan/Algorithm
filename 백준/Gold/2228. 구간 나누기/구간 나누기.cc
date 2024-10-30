#include <iostream>
#define INF -3300000
using namespace std;

int N, M;

int sum[102] = { 0, };
int DP[101][51] = { 0, };

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		sum[i] = sum[i - 1] + a;
	}

	for (int i = 1; i <= M; i++) {
		DP[0][i] = INF;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			DP[i][j] = DP[i - 1][j];
			for (int k = 1; k <= i; k++) {
				if (k > 1)DP[i][j] = max(DP[i][j], DP[k - 2][j - 1] + sum[i] - sum[k - 1]);
				if (k == 1 && j == 1) DP[i][j] = max(DP[i][j], sum[i]);
			}
		}
	}
	cout << DP[N][M];

	return 0;
}