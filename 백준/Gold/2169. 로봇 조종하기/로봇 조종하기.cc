#include <iostream>
using namespace std;

int N, M;
int map[1010][1010] = { 0, };
int DP[2][1010][2];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
	int tot = 0;
	for (int j = 1; j <= M; j++) {
		tot += map[1][j];
		DP[1][j][0] = tot;
		DP[1][j][1] = tot;
	}
	int result = 0;
	for (int i = 2; i <= N; i++) {
		int n = i % 2;
		for (int j = 0; j <= M + 1; j++) {
			DP[n][j][0] = -1e9;
			DP[n][j][1] = -1e9;
		}

		for (int j = 1; j <= M; j++) {
			int rev = M - j + 1;
			int prev_l = max(DP[!n][j][0], DP[!n][j][1]);
			int prev_r = max(DP[!n][rev][0], DP[!n][rev][1]);
			DP[n][j][0] = max(prev_l, DP[n][j - 1][0]) + map[i][j];
			DP[n][rev][1] = max(prev_r, DP[n][rev + 1][1]) + map[i][rev];
		}
	}

	cout << max(DP[N%2][M][0], DP[N%2][M][1]);

	return 0;
}