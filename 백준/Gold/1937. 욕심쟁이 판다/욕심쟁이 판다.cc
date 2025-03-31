#include <iostream>
#include <vector>
using namespace std;

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

int N;
int map[501][501] = { 0, };
int DP[501][501] = { 0, };
int max_route = 1;

int dp(int row, int col, int cnt) {

	if (DP[row][col] != 0) return DP[row][col];

	DP[row][col] = 1;
	for (int i = 0; i < 4; i++) {
		int ner = row + dr[i];
		int nec = col + dc[i];
		if (ner < 0 || nec < 0 || ner >= N || nec >= N) continue;
		if (map[ner][nec] <= map[row][col]) continue;

		DP[row][col] = max(DP[row][col], dp(ner, nec, cnt + 1) + 1);
		max_route = max(max_route, DP[row][col]);
	}

	return DP[row][col];

}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dp(i, j, 1);
		}
	}

	cout << max_route;

	return 0;
}