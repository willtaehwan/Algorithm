#include <iostream>

using namespace std;

int N, M;
int id = 1;
int ans = 0;
int map[10001][501] = { 0, };

void go(int r, int c, int idx) {

	if (c == M - 1) {
		ans++;
		id++;
		return;
	}

	for (int i = -1; i < 2; i++) {
		if (id != idx) return;
		int ner = r + i;
		int nec = c + 1;
		if (ner < 0 || nec < 0 || ner >= N || nec >= M) continue;
		if (map[ner][nec] != 0) continue;

		map[ner][nec] = idx;
		go(ner, nec, idx);
		
	}

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c;
			cin >> c;
			if (c == 'x') map[i][j] = -1;
			else map[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++) go(i, 0, id);

	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j]<<' ';
		}
		cout << '\n';
	}*/

	cout << ans;

	return 0;
}