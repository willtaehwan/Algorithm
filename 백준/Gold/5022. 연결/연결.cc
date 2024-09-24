#include <iostream>
#include <queue>
#define INF 100000
using namespace std;

struct Node {
	int row;
	int col;
};

int N, M;

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

Node dot[4];

bool map[102][102];
int visited[102][102];
int dir[102][102];

int bfs(int a, bool ty) {
	int d = a * 2;
	int sr = dot[d].row;
	int sc = dot[d].col;
	int er = dot[d + 1].row;
	int ec = dot[d + 1].col;

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			visited[i][j] = INF;
		}
	}

	map[er][ec] = false;
	queue<Node> q;
	q.push(dot[d]);
	visited[sr][sc] = 0;

	while (!q.empty()) {
		Node now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ner = now.row + dr[i];
			int nec = now.col + dc[i];
			if (ner<0 || nec<0 || ner>N || nec>M)continue;
			if (map[ner][nec]) continue;
			
			int next = visited[now.row][now.col] + 1;
			if (visited[ner][nec] <= next) continue;

			visited[ner][nec] = next;
			if(ty == 0) dir[ner][nec] = (i + 1) % 2 + (i/2) * 2;

			q.push({ ner,nec });
		}
	}
	
	if (ty == 0) {
		int endr = er;
		int endc = ec;
		while (1) {
			map[endr][endc] = true;
			if (endr == sr && endc == sc) break;
			int ned = dir[endr][endc];
			endr = endr + dr[ned];
			endc = endc + dc[ned];
		}
	}


	return visited[er][ec];

}

int search(int a) {

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			map[i][j] = 0;
		}
	}

	for (int i = 0; i < 4; i++) {
		int row = dot[i].row;
		int col = dot[i].col;
		map[row][col] = true;
	}

	int first = bfs(a, 0);
	int second = bfs((a + 1) % 2, 1);
	return first + second;
}

int main() {

	cin >> M >> N;

	for (int i = 0; i < 4; i++) {
		int r, c;
		cin >> r >> c;
		dot[i] = { c,r };
	}
	int result1, result2;

	result1 = search(0);
	result2 = search(1);

	if (result1 > result2) swap(result1, result2);
	if (result1 > 50000) cout << "IMPOSSIBLE";
	else cout << result1;

	return 0;
}