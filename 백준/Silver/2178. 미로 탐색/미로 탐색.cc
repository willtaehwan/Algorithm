#include <iostream>
#include <queue>

using namespace std;

int N, M;
int map[101][101] = { 0, };
int visited[101][101] = { 0, };

struct Node {
	int row;
	int col;
};

void bfs(int stRow, int stCol) {

	queue<Node> q;
	q.push({ stRow,stCol });
	visited[stRow][stCol] = 1;

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

			visited[ner][nec] = visited[now.row][now.col] + 1;

			q.push({ ner,nec });

		}
	}

}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string row;
		cin >> row;
		for (int j = 0; j < M; j++) {
			map[i][j] = int(row[j] - '0');
		}

	}

	bfs(0,0);

	cout << visited[N - 1][M - 1];

	return 0;
}
