#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int row;
	int col;
};

int N, Q;

int dr[] = { -1,-1,-1,0,0,1,1,1 };
int dc[] = { -1,0,1,-1,1,-1,0,1 };

int visited[5002][5002];

queue<Node> q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 5002; i++) {
		for (int j = 0; j < 5002; j++) {
			visited[i][j] = -1;
		}
	}

	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		q.push({ a, b });
		visited[a][b] = 0;
	}

	while (!q.empty()) {
		Node now = q.front(); q.pop();

		for (int i = 0; i < 8; i++) {
			int ner = now.row + dr[i];
			int nec = now.col + dc[i];
			if (ner < 0 || nec < 0 || ner >= 5001 || nec >= 5001) continue;
			if (visited[ner][nec] != -1) continue;

			visited[ner][nec] = visited[now.row][now.col] + 1;

			q.push({ ner,nec});
		}
	}


	for (int i = 0; i < Q; i++) {
		int a, b;
		cin >> a >> b;
		cout << visited[a][b] << "\n";
	}

	return 0;
}