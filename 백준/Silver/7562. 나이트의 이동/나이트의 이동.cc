#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int row;
	int col;
	int cnt;
};

int N, Tc;

int dr[] = { -1,-2,-2,-1,1,2,2,1 };
int dc[] = { -2,-1,1,2,-2,-1,1,2 };

bool visited[301][301] = { 0, };

int bfs(Node st, Node ed) {

	int result = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 0;
		}
	}


	queue<Node> q;

	q.push(st);
	visited[st.row][st.col] = 1;

	while (!q.empty()) {
		Node now = q.front(); q.pop();

		if (now.row == ed.row && now.col == ed.col) {
			result = now.cnt;
			break;
		}

		for (int i = 0; i < 8; i++) {
			int ner = now.row + dr[i];
			int nec = now.col + dc[i];
			if (ner < 0 || nec < 0 || ner >= N || nec >= N) continue;
			if (visited[ner][nec]) continue;

			visited[ner][nec] = 1;
			q.push({ ner,nec, now.cnt + 1 });

		}

	}


	return result;
}

int main() {

	cin >> Tc;

	for (int t = 0; t < Tc; t++) {
		cin >> N;

		Node st;
		Node ed;

		cin >> st.row >> st.col;
		cin >> ed.row >> ed.col;
		st.cnt = 0;
		cout << bfs(st, ed) << '\n';

	}


	return 0;
}