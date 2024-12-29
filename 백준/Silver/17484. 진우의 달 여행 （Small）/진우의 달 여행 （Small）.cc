#include <iostream>

using namespace std;

int N, M;

int map[6][6] = { 0, };
int DP[6][6][3] = {0,};

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			for (int k = 0; k < 3; k++) {
				if (i == 0) DP[i][j][k] = map[i][j];
				else DP[i][j][k] = 1e9;
			}
		}
	}
	int min_result = 1e9;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 3; k++) {
				int prc = j + k - 1;
				if (prc < 0 || prc >= M) continue;
				for (int l = 0; l < 3; l++) {
					if (k == l) continue;
					DP[i][j][k] = min(DP[i][j][k], DP[i - 1][j + k - 1][l] + map[i][j]);
					if (i == N - 1) min_result = min(min_result, DP[i][j][k]);
				}
			}
		}
	}

	cout << min_result;

	return 0;

}