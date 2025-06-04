#include <iostream>

using namespace std;

int N;

int visited[16][16];

int dr[] = { -1,-1,1,1 };
int dc[] = { -1,1,-1,1 };
int ans = 0;

void dfs(int cnt, int col) {

	if (cnt == N) {
		ans++;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visited[cnt][i] != 0) continue;
		if (col & (1 << i)) continue;

		int next_c = col + (1 << i);

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 4; k++) {
				int ner = cnt + dr[k] * j;
				int nec = i + dc[k] * j;
				if (ner < 0 || nec < 0 || ner >= N || nec >= N) continue;

				visited[ner][nec] += 1;
			}
		}
		
		dfs(cnt + 1, next_c);
		
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 4; k++) {
				int ner = cnt + dr[k] * j;
				int nec = i + dc[k] * j;
				if (ner < 0 || nec < 0 || ner >= N || nec >= N) continue;

				visited[ner][nec] -= 1;
			}
		}

	}

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	dfs(0, 0);

	cout << ans;

	return 0;
}