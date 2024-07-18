#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int row;
	int col;
	int dir;
	int cost;

	bool operator<(Node left) const{
		return cost > left.cost;
	}
};

int H, W;

char map[101][101] = { 0, };
int temp[101][101] = {0,};
bool check[101][101][4] = { 0, };

Node c[2];

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

void bfs(Node st) {

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			temp[i][j] = 10001;
		}
	}

	priority_queue<Node> pq;
	pq.push(st);
	temp[st.row][st.col] = 0;

	while (!pq.empty()) {
		Node now = pq.top(); pq.pop();

		if (now.cost > temp[now.row][now.col]) continue;
		if (temp[c[1].row][c[1].col] <= now.cost) continue;

		if (check[now.row][now.col][now.dir]) continue;
		check[now.row][now.col][now.dir] = true;

		for (int i = 0; i < 4; i++) {
			int ner = now.row + dr[i];
			int nec = now.col + dc[i];
			int ne_cost = now.cost;
			if (now.dir != i) ne_cost++;

			if (ner < 0 || nec < 0 || ner >= H || nec >= W) continue;
			if (map[ner][nec] == '*') continue;

			if (temp[ner][nec] < ne_cost) continue;

			temp[ner][nec] = ne_cost;
			pq.push({ ner,nec,i,ne_cost });

		}

	}

}

int main() {

	cin >> W >> H;
	int cnt = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'C') c[cnt++] = { i,j,-1,0 };
		}
	}

	bfs(c[0]);

	cout << temp[c[1].row][c[1].col] - 1;

	return 0;
}