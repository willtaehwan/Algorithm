#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int row;
	int col;
	int cnt;
};

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

int N;
int map[101][101] = { 0, };

int visited[101][101] = { 0, };

void bfs(int row, int col, int idx) {

	queue<Node> q;
	q.push({ row, col });
	map[row][col] = idx;

	while (!q.empty()) {
		Node now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ner = now.row + dr[i];
			int nec = now.col + dc[i];
			if (ner < 0 || nec < 0 || ner >= N || nec >= N) continue;
			if (map[ner][nec] == 0) continue;
			if (map[ner][nec] == idx) continue;

			map[ner][nec] = idx;
			q.push({ ner,nec });
		}
	}
}

int bfs2(int row, int col) {

	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 1e9;
		}
	}*/

	queue<Node> q;
	q.push({ row, col, 0 });
	int now_idx = map[row][col];
	int res = 1e9;

	while (!q.empty()) {
		Node now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ner = now.row + dr[i];
			int nec = now.col + dc[i];
			if (ner < 0 || nec < 0 || ner >= N || nec >= N) continue;

			if (map[ner][nec]) {
				if (map[ner][nec] != now_idx) res = min(res, now.cnt);
				continue;
			}
			if (visited[ner][nec] <= now.cnt) continue;

			visited[ner][nec] = now.cnt;
			q.push({ ner,nec, now.cnt + 1 });
		}


	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			visited[i][j] = 1e9;
		}
	}

	int cnt = 2;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] != 1) continue;
			bfs(i, j, cnt);
			cnt++;
		}
	}

	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j] << " ";
		}
		cout << '\n';
	}*/

	int ans = 1e9;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!map[i][j]) continue;
			ans = min(ans, bfs2(i, j));
		}
	}
	cout << ans;

	return 0;
}