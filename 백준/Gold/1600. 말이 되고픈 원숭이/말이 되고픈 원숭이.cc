#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
	int row;
	int col;
	int cnt;
};

int dr[] = { -1,1,0,0,-1,-2,-2,-1,1,2,2,1 };
int dc[] = { 0,0,-1,1,-2,-1,1,2,-2,-1,1,2 };

int K, N, M;
bool map[201][201] = { 0, };
int visited[201][201][31] = { 0, };



void bfs() {

	queue<Node> q;
	q.push({ 0,0,0 });
	visited[0][0][0] = 0;

	while (!q.empty()) {
		Node now = q.front(); q.pop();
		int d = 4;
		if (now.cnt < K) d = 12;

		for (int i = 0; i < d; i++) {
			int ner = now.row + dr[i];
			int nec = now.col + dc[i];
			int necnt = now.cnt;
			if (ner < 0 || nec < 0 || ner >= N || nec >= M) continue;
			if (map[ner][nec]) continue;

			if (i > 3) necnt += 1;
			if (visited[ner][nec][necnt] <= visited[now.row][now.col][now.cnt] + 1) continue;

			visited[ner][nec][necnt] = visited[now.row][now.col][now.cnt] + 1;
			q.push({ ner,nec,necnt });
		}

	}

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> K >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			for (int k = 0; k <= K; k++) visited[i][j][k] = 1e9;
		}
	}

	bfs();
	int ans = 1e9;
	for (int i = 0; i <= K; i++) ans = min(ans, visited[N-1][M-1][i]);
	
	/*for (int k = 0; k <= K; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (visited[i][j][k] == 1e9) cout << "X ";
				else cout << visited[i][j][k]<<" ";
			}
			cout << '\n';
		}
		cout << "\n\n";
	}*/

	
	if (ans != 1e9) cout << ans;
	else cout << -1;
	
	

	return 0;
}