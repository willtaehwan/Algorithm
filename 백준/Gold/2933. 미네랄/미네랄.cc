#include <iostream>
#include <queue>
using namespace std;


int map[110][110] = { 0, };
int visited[101][101] = { 0, };


struct Node {
	int row;
	int col;
};

int R, C, N;

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

void gravity() {

	int down = 999;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (visited[i][j] == 0) continue;
			if (visited[i + 1][j] == 1) continue;
			int col = i;
			int temp = 0;
			while (1) {
				col++;
				if (col == R) break;
				if (map[col][j] == 1 && visited[col][j] != 1) break;
				temp++;
			}
			if (down > temp) down = temp;
		}
	}

	for (int i = R - 1; i >= 0; i--) {
		for (int j = 0; j < C; j++) {
			if (visited[i][j] == 0) continue;
			map[i + down][j] = 1;
			map[i][j] = 0;
		}
	}
}

void bfs_ch(Node st) {

	if (st.row < 0 || st.col < 0 || st.row >= R || st.col >= C) return;
	if (map[st.row][st.col] == 0) return;
	if (st.row == R - 1) return;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			visited[i][j] = 0;
		}
	}

	queue<Node> q;
	q.push(st);

	visited[st.row][st.col] = 1;
	bool gnd_flag = false;

	while (!q.empty()) {
		Node now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ner = now.row + dr[i];
			int nec = now.col + dc[i];

			if (ner < 0 || nec < 0 || ner >= R || nec >= C) continue;
			if (map[ner][nec] == 0) continue;
			if (visited[ner][nec] != 0) continue;

			visited[ner][nec] = 1;

			if (ner == R - 1) gnd_flag = true;

			q.push({ ner,nec });

		}

	}

	if (!gnd_flag) gravity();

}


void shoot(int h, bool dir) {

	// 0 : left, 1 : right
	if (!dir) {
		for (int i = 0; i < C; i++) {
			if (map[R - h][i] == 1) {
				map[R - h][i] = 0;
				bfs_ch({ R - h + 1,i });
				bfs_ch({ R - h - 1,i });
				bfs_ch({ R - h, i + 1 });
				break;
			}
		}
	}
	else {
		for (int i = C - 1; i >= 0; i--) {
			if (map[R - h][i] == 1) {
				map[R - h][i] = 0;
				bfs_ch({ R - h + 1,i });
				bfs_ch({ R - h - 1,i });
				bfs_ch({ R - h, i - 1 });
				break;
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char p;
			cin >> p;
			if (p == 'x') map[i][j] = 1;
		}
	}

	cin >> N;

	for (int i = 0; i < N; i++) {
		int h;
		cin >> h;
		shoot(h, i % 2);
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 1) cout << 'x';
			else cout << '.';
		}
		cout << '\n';
	}


	return 0;
}