#include <iostream>

using namespace std;

int N, M;

int map[6][6] = { 0, };
int DP[6][6][3] = {0,};

int dp(int row, int col, int dir) {

	if (DP[row][col][dir] != -1) return DP[row][col][dir];

	int prc = col + dir - 1;
	if (prc < 0 || prc >= M) return 1e9;

	int result = 1e9;
	for (int i = 0; i < 3; i++) {
		if (dir == i) continue;
		result = min(result, dp(row - 1, prc, i) + map[row][col]);
	}
	DP[row][col][dir] = result;

	return result;
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			for (int k = 0; k < 3; k++) {
				if (i == 0) DP[i][j][k] = map[i][j];
				else DP[i][j][k] = -1;
			}
		}
	}
	int min_result = 1e9;
	for (int i = 0; i < M; i++) {
		for (int k = 0; k < 3; k++) {
			min_result = min(min_result, dp(N - 1, i, k));
		}
	}

	cout << min_result;

	return 0;

}