#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct heater {
	int row;
	int col;
	int dir;
	int tem;
};

int N, M, K, W;

int map[21][21] = { 0, };
int tem[21][21] = { 0, };
bool wall[21][21][4] = { 0, };

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };
int in_d[] = { 0,3,2,0,1 };

int w_ch[4][3] = {
	{2, 0, 3},
	{2, 1, 3},
	{0, 2, 1},
	{0, 3, 1}
};

int choco = 0;

vector<heater> v;
vector<heater> sk;

void wall_gen(int x, int y, int t) {

	if (t) {
		wall[x][y][3] = true;
		wall[x][y + 1][2] = true;
	}
	else {
		wall[x][y][0] = true;
		wall[x - 1][y][1] = true;
	}
}

void w_bfs(heater n) {

	int visited[21][21] = { 0, };
	queue<heater> q;

	//if (wall[n.row][n.col][n.dir]) return;
	int ser = n.row + dr[n.dir];
	int sec = n.col + dc[n.dir];
	//if (ser < 0 || sec < 0 || ser >= N || sec >= M) return;
	visited[ser][sec] = n.tem;
	q.push({ ser,sec,n.dir, n.tem - 1 });
	
	while (!q.empty()) {
		heater now = q.front(); q.pop();

		for (int i = -1; i < 2; i++) {
			if (wall[now.row][now.col][w_ch[now.dir][i + 1]]) continue;
			int ner = now.row + dr[now.dir];
			int nec = now.col + dc[now.dir];
			if (now.dir < 2) nec += i;
			else ner += i;
			if (ner < 0 || nec < 0 || ner >= N || nec >= M) continue;
			if (visited[ner][nec] != 0) continue;
			int p_dir = 0;
			if (now.dir % 2 == 0) p_dir = now.dir + 1;
			else p_dir = now.dir - 1;

			if (wall[ner][nec][p_dir]) continue;

			visited[ner][nec] = now.tem;
			if (now.tem - 1 == 0) continue;
			q.push({ ner,nec,now.dir, now.tem - 1 });

		}

	}
	//cout << '\n';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			tem[i][j] += visited[i][j];
			//cout << visited[i][j]<<" ";
		}
		//cout << '\n';
	}
	//cout << '\n';
}

void wind() {

	for (int i = 0; i < v.size(); i++) {
		heater now = v[i];
		w_bfs(now);
	}

}

void regulate() {

	int p_temp[21][21] = { 0, };
	int m_temp[21][21] = { 0, };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			if (tem[i][j] == 0) continue;
			int now = tem[i][j];
			for (int k = 0; k < 4; k++) {
				int ner = i + dr[k];
				int nec = j + dc[k];
				if (ner < 0 || nec < 0 || ner >= N || nec >= M) continue;
				if (now <= tem[ner][nec]) continue;
				if (wall[i][j][k]) continue;

				int sub = (now - tem[ner][nec]) / 4;
				p_temp[ner][nec] += sub;
				m_temp[i][j] -= sub;
			}

		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			tem[i][j] = tem[i][j] + p_temp[i][j] + m_temp[i][j];
		}
	}

}

void freeze() {

	for (int i = 0; i < N; i++) {
		bool flag = false;
		if (i == 0 || i == N - 1) flag = true;

		for (int j = 0; j < M; j++) {
			if (flag) {
				if (tem[i][j] != 0) tem[i][j]--;
				continue;
			}
			if (j == 0 || j == M - 1) {
				if (tem[i][j] != 0) tem[i][j]--;
			}
		}
	}
}

bool search_k() {
	bool flag = true;
	for (int i = 0; i < sk.size(); i++) {
		heater now = sk[i];
		if (tem[now.row][now.col] < K) {
			flag = false;
			break;
		}
	}

	return flag;
}

int main() {

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] > 0 && map[i][j] < 5) v.push_back({ i,j,in_d[map[i][j]],5 });
			if (map[i][j] == 5) sk.push_back({ i,j,0,0 });
		}
	}

	cin >> W;

	for (int i = 0; i < W; i++) {
		int x, y, t;
		cin >> x >> y >> t;
		wall_gen(x - 1, y - 1, t);
	}

	while (choco < 101) {

		wind();
		regulate();
		freeze();
		choco++;

		if (search_k()) break;

	}

	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << tem[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';*/


	cout << choco;

	return 0;
}