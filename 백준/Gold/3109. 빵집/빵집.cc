#include <iostream>

using namespace std;

int N, M;
int id = 1;
int ans = 0;
bool map[10001][501] = { 0, };

bool go(int r, int c) {

	if (c == M - 1) return 1;
	if (r < 0 || c < 0 || r >= N || c >= M) return 0;
	if (map[r][c]) return 0;

	map[r][c] = 1;

	return (go(r-1, c+1) || go(r, c+1) || go(r+1, c+1));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c;
			cin >> c;
			if (c == 'x') map[i][j] = 1;
			else map[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++) ans += go(i, 0);
	cout << ans;

	return 0;
}