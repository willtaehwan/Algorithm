#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M, K;
int map[51][51] = { 0, };
int visited[51][51] = { 0, };
int cnt = 1;
struct Node {
	int row;
	int col;
};

vector<Node> v;

void init() {
	N = M = K = 0;
	v.clear();
	cnt = 0;
	memset(map, 0, sizeof(map));
	memset(visited, 0, sizeof(visited));
}

void input() {
	cin >> M >> N >> K;

	for (int i = 0; i < K; i++) {
		int row, col;
		cin >> col >> row;
		map[row][col] = 1;
		v.push_back({ row,col });

	}

}

void bfs(int row, int col) {

	if (visited[row][col] != 0) {
		return;
	}
	cnt++;
	queue<Node> q;
	q.push({ row,col });
	visited[row][col] = cnt;
	
	while (!q.empty()) {
		Node now = q.front(); q.pop();

		int dr[] = { -1,1,0,0 };
		int dc[] = { 0,0,-1,1 };
		for (int i = 0; i < 4; i++) {
			int ner = now.row + dr[i];
			int nec = now.col + dc[i];

			if (ner < 0 || nec < 0 || ner >= N || nec >= M) {
				continue;
			}

			if (visited[ner][nec] != 0) {
				continue;
			}

			if (map[ner][nec] == 0) {
				continue;
			}

			visited[ner][nec] = cnt;
			q.push({ ner,nec });

		}


	}
}

int main() {

	int T;

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {

		init();
		input();
		
		for (int i = 0; i < v.size(); i++) {
			bfs(v[i].row, v[i].col);
		}
		
		/*for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << visited[i][j]<<" ";
			}
			cout << endl;
		}*/
		cout << cnt << endl;
	}

	return 0;
}