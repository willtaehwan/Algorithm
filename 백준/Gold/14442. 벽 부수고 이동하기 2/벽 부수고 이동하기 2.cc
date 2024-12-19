#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int row;
	int col;
	int cnt;
	int dis;
};

int N, M, K;
bool map[1001][1001] = { 0, };
int n_map[1000][1001] = { 0, };

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

int bfs() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			n_map[i][j] = -1;
		}
	}

	queue<Node> q;
	q.push({ 0, 0, K,1 });
	n_map[0][0] = 1;


	while (!q.empty()) {
		Node now = q.front(); q.pop();

		if (now.row == N - 1 && now.col == M - 1) return now.dis;

		for (int i = 0; i < 4; i++) {
			int ner = now.row + dr[i];
			int nec = now.col + dc[i];
			int nect = now.cnt;
			if (ner < 0 || nec < 0 || ner >= N || nec >= M) continue;
			if (map[ner][nec]) nect--;
			if (nect < 0) continue;
			if (n_map[ner][nec] < nect || n_map[ner][nec] == -1) {
				n_map[ner][nec] = nect;
				q.push({ ner,nec,nect, now.dis + 1 });
			}
		}

	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {
			if (str[j] == '0') map[i][j] = false;
			else map[i][j] = true;
		}
	}

	cout << bfs();
	
	return 0;
}