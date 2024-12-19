#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int row;
	int col;
	int cnt;
};

int N, M, K;
bool map[1001][1001] = { 0, };
int n_map[1000][1001][11] = { 0, };

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

void bfs() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k <= K; k++) {
				n_map[i][j][k] = 1e9;
			}
		}
	}

	queue<Node> q;
	q.push({ 0, 0, K });
	n_map[0][0][K] = 1;


	while (!q.empty()) {
		Node now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ner = now.row + dr[i];
			int nec = now.col + dc[i];
			int nect = now.cnt;
			if (ner < 0 || nec < 0 || ner >= N || nec >= M) continue;
			if (map[ner][nec]) nect--;
			if (nect < 0) continue;
			if (n_map[ner][nec][nect] <= n_map[now.row][now.col][now.cnt] + 1) continue;

			n_map[ner][nec][nect] = n_map[now.row][now.col][now.cnt] + 1;
			q.push({ ner,nec,nect });
		}

	}

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

	
	bfs();
	/*for (int k = 0; k <= K; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (n_map[i][j][k] == 1e9) cout << "X ";
				else cout << n_map[i][j][k] << " ";
			}
			cout << '\n';
		}
		cout << "\n\n";
	}*/
	
	int result = 1e9;
	for (int i = 0; i <= K; i++) result = min(result, n_map[N - 1][M - 1][i]);
	
	if (result == 1e9) cout << -1;
	else cout << result;
	
	return 0;
}