#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int row;
	int col;
};

int N;
int map[126][126] = { 0, };
int visited[126][126] = { 0, };

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

int bfs() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 1e9;
		}
	}

	queue<Node> q;
	q.push({ 0,0 });
	visited[0][0] = map[0][0];

	while (!q.empty()) {
		Node now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ner = now.row + dr[i];
			int nec = now.col + dc[i];
			if (ner < 0 || nec < 0 || ner >= N || nec >= N) continue;
			
			int next = visited[now.row][now.col] + map[ner][nec];
			if (visited[ner][nec] <= next) continue;

			visited[ner][nec] = next;
			q.push({ ner,nec });
		}
	}

	return visited[N - 1][N - 1];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int cnt = 0;
	while (1) {
		cnt++;
		cin >> N;

		if (N == 0) return 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		cout<<"Problem "<<cnt<<": "<< bfs()<<'\n';
	}
	
	return 0;
}