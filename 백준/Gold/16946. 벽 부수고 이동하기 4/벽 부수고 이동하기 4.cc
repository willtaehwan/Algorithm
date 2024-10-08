#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

struct Node {
	int row;
	int col;
};

int N, M;

int map[1001][1001] = { 0, };

vector<int> v;

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

void bfs(int row, int col, int num) {

	int cnt = 1;
	queue<Node> q;
	q.push({ row, col });
	map[row][col] = -num;

	while (!q.empty()) {
		Node now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ner = now.row + dr[i];
			int nec = now.col + dc[i];
			if (ner < 0 || nec < 0 || ner >= N || nec >= M) continue;
			if (map[ner][nec] != 0) continue;
			map[ner][nec] = -num;
			q.push({ ner,nec });
			cnt++;
		}
	}
	v.push_back(cnt);
}

int check(int row, int col) {

	int result = 1;
	set<int> s;
	for (int i = 0; i < 4; i++) {
		int ner = row + dr[i];
		int nec = col + dc[i];
		if (ner < 0 || nec < 0 || ner >= N || nec >= M) continue;
		if (map[ner][nec] == 1) continue;
		s.insert(-map[ner][nec]);
	}

	for (auto it : s) result += v[it - 1];
	return result % 10;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {
			map[i][j] = str[j] - '0';
		}
	}

	int area_idx = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) bfs(i, j, area_idx++);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) cout << check(i, j);
			else cout << 0;
		}
		cout << '\n';
	}

	return 0;
}