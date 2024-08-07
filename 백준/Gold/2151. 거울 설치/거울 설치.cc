#include <iostream>

#include <queue>
#define MAX 3001
using namespace std;

struct Node {
	int row;
	int col;
	int dir;
	int cost;

	bool operator<(Node left) const {
		if (cost > left.cost) return true;
		else return false;
	}

};

int N;

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

int nextdir[4][2] = {
	{2,3}, {2,3}, {0,1}, {0,1}
};
char map[51][51];
int visited[51][51] = { 0, };
Node door[2];

int min_cost = 1e9;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	int cnt = 0;

	queue<Node> pq;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == '#') door[cnt++] = {i,j,0,0};
			if (map[i][j] == '#' || map[i][j] == '!') visited[i][j] = MAX;
		}
	}

	for (int i = 0; i < 4; i++) pq.push({ door[0].row, door[0].col, i,0 });

	while (!pq.empty()) {
		Node now = pq.front(); pq.pop();

		int k = 0;
		while (1) {
			k++;
			int ner = now.row + dr[now.dir] * k;
			int nec = now.col + dc[now.dir] * k;
			if (ner < 0 || nec < 0 || ner >= N || nec >= N) break;
			if (map[ner][nec] == '*') break;

			if (map[ner][nec] == '!') {
				if (visited[ner][nec] < now.cost) continue;
				visited[ner][nec] = now.cost;

				pq.push({ ner,nec,nextdir[now.dir][0], now.cost + 1 });
				pq.push({ ner,nec,nextdir[now.dir][1], now.cost + 1 });
			}

			if (map[ner][nec] == '#') {
				if (visited[ner][nec] < now.cost) continue;
				visited[ner][nec] = now.cost;
				break;
			}
		}

	}

	cout << visited[door[1].row][door[1].col];


	return 0;
}