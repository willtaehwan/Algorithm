#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int row;
	int col;
	int cnt;
};

int dr[] = { 0, 0, 0,-1,-1,-1,-2,-2,-2 };
int dc[] = {-1, 0, 1,-1, 0, 1,-1, 0, 1 };

char map[8][8];

bool bfs(int row, int col) {

	queue<Node> q;
	q.push({ row,col,0 });

	while (!q.empty()) {
		Node now = q.front(); q.pop();

		if (now.row <= 0 ) return true;

		int st = 0;
		if (now.cnt < 1) st = 3;

		for (int i = st; i < 9; i++) {
			
			int ner = now.row + dr[i];
			int nec = now.col + dc[i];
			int noc = now.cnt;
			if (nec < 0 || ner >= 8 || nec >= 8) continue;
			if (map[ner][nec] == '#') continue;
			if (map[ner + 1][nec] == '#') continue;

			if (i >= 6) noc++;
			if (i < 3) noc--;
			q.push({ ner,nec,noc });
		}
	}

	return false;
}


int main() {

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> map[i][j];
		}
	}

	cout<<bfs(7, 0);

	return 0;
}