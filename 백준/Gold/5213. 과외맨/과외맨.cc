#include <iostream>
#include <queue>
#include <stack>
#define INF 250002
using namespace std;

struct Node {
	int row;
	int col;
};

struct tile {
	int l;
	int r;
	int num;
};

int N;

int dr[] = { -1,0,1,-1,0,1 };

int dc[2][6] = {
	{-1,-1,-1,0,1,0},
	{ 0, -1,0,1,1,1 }
};

tile map[501][501];
int visited[501][501];

Node tar;
int tar_num = 1;
int tar_fin = 1;
bool flag = true;
stack<int> s;

void t_dfs(int row, int col, int num) {

	if (visited[row][col] == 1 && flag) {
		cout << s.size() << '\n';
		while(!s.empty()){
			int now = s.top();
			cout << now << " ";
			s.pop();
		}
		flag = false;
		return;
	}

	for (int i = 0; i < 6; i++) {
		int ner = row + dr[i];
		int nec = col + dc[row % 2][i];

		if (ner < 0 || nec < 0 || ner >= N || nec >= N) continue;
		if (visited[ner][nec] != num - 1) continue;

		if (i < 3 && map[ner][nec].r != map[row][col].l) continue;
		if (i > 2 && map[ner][nec].l != map[row][col].r) continue;

		s.push(map[ner][nec].num);
		t_dfs(ner, nec, num - 1);
		if (!flag) return;
		if(s.size() != 0) s.pop();

	}


}

void bfs(int row, int col) {

	queue<Node> q;
	q.push({ row, col});
	visited[row][col] = 1;

	while (!q.empty()) {
		Node now = q.front(); q.pop();

		for (int i = 0; i < 6; i++) {
			int ner = now.row + dr[i];
			int nec = now.col + dc[now.row % 2][i];

			if (ner < 0 || nec < 0 || ner >= N || nec >= N) continue;

			if (i < 3 && map[ner][nec].r != map[now.row][now.col].l) continue;
			if (i > 2 && map[ner][nec].l != map[now.row][now.col].r) continue;

			if (visited[ner][nec] <= visited[now.row][now.col] + 1) continue;
			visited[ner][nec] = visited[now.row][now.col] + 1;
			
			if (map[ner][nec].num > tar_num) {
				tar = { ner,nec };
				tar_num = map[ner][nec].num;
				tar_fin = visited[ner][nec];
			}
			q.push({ ner,nec });

		}

	}

}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	int idx = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = INF;
			if (i % 2 == 1 && j == N - 1) {
				map[i][j] = { -1,-1 };
				continue;
			}
			int a, b;
			cin >> a >> b;
			map[i][j] = { a,b, idx++ };
		}
	}

	bfs(0, 0);
	s.push(tar_num);
	t_dfs(tar.row, tar.col, tar_fin);


	return 0;
}