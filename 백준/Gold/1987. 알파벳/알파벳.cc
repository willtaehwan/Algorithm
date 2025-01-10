#include <iostream>
#include <queue>
using namespace std;

int N, M;

int map[21][21];
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

int max_result = 1;
void dfs(int row, int col, int cnt, int bit) {

	for (int i = 0; i < 4; i++) {
		int ner = row + dr[i];
		int nec = col + dc[i];
		if (ner < 0 || nec < 0 || ner >= N || nec >= M) continue;

		int neb = 1 << map[ner][nec];
		if (bit & neb) continue;

		max_result = max(max_result, cnt + 1);
		dfs(ner, nec, cnt + 1, (bit | neb));
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {
			map[i][j] = (int)(str[j] - 'A');
		}
	}

	dfs(0,0,1,(1<<map[0][0]));
	cout << max_result;

	return 0;
}