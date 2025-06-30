#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int row;
	int col;
	int cnt;
	bool flag;
};

int N, M;
bool map[1001][1001] = { 0, };
int visited[1001][1001][2] = {0,};

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

void bfs() {

	visited[0][0][1] = 1;
	queue<Node> q;
	q.push({ 0, 0, 1, 1 });

	while (!q.empty()) {

		Node now = q.front(); q.pop();

		if (visited[now.row][now.col][now.flag] < now.cnt) continue;

		for (int i = 0; i < 4; i++) {
			int ner = now.row + dr[i];
			int nec = now.col + dc[i];
			bool nef = now.flag;
			if (ner < 0 || nec < 0 || ner >= N || nec >= M) continue;
			if (map[ner][nec]) {
				if (now.flag) nef = false;
				else continue;
			}
			
			if (visited[ner][nec][nef] <= visited[now.row][now.col][now.flag] + 1) continue;
			visited[ner][nec][nef] = visited[now.row][now.col][now.flag] + 1;

			q.push({ ner,nec,now.cnt + 1, nef });

		}
	}

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			map[i][j] = int(s[j] - '0');
			visited[i][j][0] = 1e9;
			visited[i][j][1] = 1e9;
		}
	}

	bfs();

	int ans = min(visited[N - 1][M - 1][0], visited[N - 1][M - 1][1]);
	if (ans == 1e9) cout << -1;
	else cout << ans;

	return 0;
}