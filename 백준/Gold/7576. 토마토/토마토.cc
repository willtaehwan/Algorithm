#include <iostream>
#include <queue>
using namespace std;

int N, M;

int map[1001][1001] = { 0, };
int visited[1001][1001] = { 0, };

struct Node {
	int row;
	int col;
};




int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;

	queue<Node> q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				q.push({ i,j });
				visited[i][j] = 1;
			}
		}
	}

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
			if (map[ner][nec] == -1) continue;
			if (visited[ner][nec] <= visited[now.row][now.col] + 1
				&& visited[ner][nec] != 0) continue;

			visited[ner][nec] = visited[now.row][now.col] + 1;

			q.push({ ner,nec });

		}
	}
	int maxDate = 0;
	int flag = 0;
	for (int i = 0; i < N; i++) {

		if (flag == 1) break;

		for (int j = 0; j < M; j++) {
			//cout << visited[i][j] << " ";
			if (visited[i][j] == 0 && map[i][j] != -1) {
				flag = 1;
				break;
			}
			if (maxDate < visited[i][j]) {
				maxDate = visited[i][j];
			}
		}
		//cout << endl;
	}

	if (flag == 1) {
		cout << -1;
	}
	else {
		cout << maxDate-1;
	}
	

	return 0;
}