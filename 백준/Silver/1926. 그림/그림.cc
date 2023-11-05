#include <iostream>
#include <queue>
using namespace std;

int N, M;

int map[501][501] = { 0, };
int visited[501][501] = { 0, };
int maxSize = 0;

struct Node {
	int row;
	int col;
};

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

void bfs(int strow, int stcol) {

	queue<Node> q;
	q.push({ strow,stcol });
	visited[strow][stcol] = 1;
	int size = 1;
	while (!q.empty()) {
		Node now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ner = now.row + dr[i];
			int nec = now.col + dc[i];

			if (ner < 0 || nec < 0 || ner >= N || nec >= M) continue;
			if (map[ner][nec] == 0) continue;
			if (visited[ner][nec] != 0) continue;

			size++;
			visited[ner][nec] = size;
			
			q.push({ ner,nec });

		}


	}

	if (size > maxSize) {
		maxSize = size;
	}

	return;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	int artCnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			
			if (map[i][j] == 0) continue;

			if (visited[i][j] != 0) continue;
			artCnt++;
			bfs(i, j);
		}
	}

	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}*/

	cout << artCnt << endl;
	cout << maxSize;

	return 0;
}