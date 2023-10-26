#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
	int row;
	int col;
};

int N;

int dr[] = { 0,-1,0,1 };
int dc[] = { 1,0,-1,0 };

int visited[101][101] = { 0, };

vector<int> dir;

int max_row = 0;
int max_col = 0;

void dfs(int now, int gen, int y, int x) {

	if (now == gen) {

		int nor = y;
		int noc = x;

		for (int i = 0; i < dir.size(); i++) {
			int ner = nor + dr[dir[i]];
			int nec = noc + dc[dir[i]];

			visited[ner][nec] = 1;

			if (ner > max_row) max_row = ner;
			if (nec > max_col) max_col = nec;

			nor = ner;
			noc = nec;
		}

		return;
	}

	for (int i = dir.size() - 1; i >= 0; i--) {
		int ned = (dir[i] + 1) % 4;
		dir.push_back(ned);
	}

	dfs(now + 1, gen, y, x);

}

int main() {

	
	cin >> N;

	for (int i = 0; i < N; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		dir.clear();
		dir.push_back(d);
		visited[y][x] = 1;
		dfs(0, g, y, x);
	}

	int cnt = 0;

	for (int i = 0; i < max_row; i++) {
		for (int j = 0; j < max_col; j++) {
			if (visited[i][j] + visited[i][j + 1] + visited[i + 1][j] + visited[i + 1][j + 1] == 4) {
				cnt++;
			}
		}
	}

	cout << cnt;
	
	return 0;
}