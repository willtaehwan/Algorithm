#include <iostream>
using namespace std;

int N, M;
int map[1010][1010] = { 0, };
int DP[1010][1010][2];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
	int tot = 0;
	for (int i = 1; i <= M; i++) {
		tot += map[1][i];
		DP[1][i][0] = tot;
		DP[1][i][1] = tot;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= M + 1; j++) {
			DP[i][j][0] = -1e9;
			DP[i][j][1] = -1e9;
		}

		for (int j = 1; j <= M; j++) {
			int rev = M - j + 1;
			int prev_l = max(DP[i - 1][j][0], DP[i - 1][j][1]);
			int prev_r = max(DP[i - 1][rev][0], DP[i - 1][rev][1]);
			DP[i][j][0] = max(prev_l, DP[i][j - 1][0]) + map[i][j];
			DP[i][rev][1] = max(prev_r, DP[i][rev + 1][1]) + map[i][rev];
		}
	}

	cout << max(DP[N][M][0], DP[N][M][1]);

	return 0;
}