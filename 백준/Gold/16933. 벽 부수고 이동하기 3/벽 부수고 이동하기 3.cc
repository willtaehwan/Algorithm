#include <iostream>
#include <queue>
#include <algorithm>
#define INF 1e9

using namespace std;

struct Node {
	int row;
	int col;
	bool time;
	int cost;
	int boom;
};

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

int N, M, K;

bool map[1002][1002];

int visited[1002][1002][11] = { 0, };

int result = INF;
bool flag = false;
void bfs() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k <= K; k++) {
				visited[i][j][k] = INF;
			}
		}
	}

	queue<Node> q;
	q.push({ 0,0,0,0,K });
	visited[0][0][K] = 0;

	while (!q.empty()) {
		Node now = q.front(); q.pop();

		if (now.row == N - 1 && now.col == M - 1) {
			result = min(result,now.cost);
			flag = true;
			continue;
		}

		if (visited[now.row][now.col][now.boom] < now.cost) continue;

		for (int i = 0; i < 4; i++) {
			int ner = now.row + dr[i];
			int nec = now.col + dc[i];
			bool net = !now.time;
			int neb = now.boom;
			int nect = now.cost + 1;
			if (ner < 0 || nec < 0 || ner >= N || nec >= M)continue;
			if (map[ner][nec]) {
				if (now.time) {
					nect++;
					net = !net;
				}
				neb--;
			}
			if (neb < 0) continue;
			if (visited[ner][nec][neb] <= nect) continue;
			visited[ner][nec][neb] = nect;
			q.push({ ner, nec, net, nect, neb });
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {
			map[i][j] = str[j] - '0';
		}
	}

	bfs();

	if (flag) cout << result + 1;
	else cout << -1;

	return 0;
}
