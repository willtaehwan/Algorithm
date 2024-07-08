#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int row;
	int col;
};

int R, C;
int visited[1510][1510] = { 0, };
int d_visited[1510][1510] = { 0, };

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

Node swan[2];

bool meet_flag = false;

queue<Node> q;
queue<Node> qq;
queue<Node> nextq;

void bfs_ch(int cnt) {
	
	while (!nextq.empty()) {
		Node el = nextq.front(); nextq.pop();
		q.push(el);
	}

	while (!q.empty()) {
		Node now = q.front(); q.pop();

		if (meet_flag) continue;

		for (int i = 0; i < 4; i++) {
			int ner = now.row + dr[i];
			int nec = now.col + dc[i];

			if (ner < 0 || nec < 0 || ner >= R || nec >= C) continue;
			if (d_visited[ner][nec] != 0) continue;
			if (visited[ner][nec] == cnt + 1) {
				visited[ner][nec] = -1;
				nextq.push({ ner,nec });
				continue;
			}
			if (visited[ner][nec] == -1) continue;
			if (ner == swan[1].row && nec == swan[1].col) meet_flag = true;
			d_visited[ner][nec] = 1;
			
			q.push({ ner,nec });

		}
	}
}


int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C;
	int cnt = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char now;
			cin >> now;
			if (now == 'L') swan[cnt++] = { i,j };
			if (now == 'X') continue;
			qq.push({ i,j });
			visited[i][j] = 1;
		}
	}
	
	while (!qq.empty()) {
		Node now = qq.front(); qq.pop();

		for (int i = 0; i < 4; i++) {
			int ner = now.row + dr[i];
			int nec = now.col + dc[i];

			if (ner < 0 || nec < 0 || ner >= R || nec >= C) continue;

			if (visited[ner][nec] != 0) continue;

			visited[ner][nec] = visited[now.row][now.col] + 1;

			qq.push({ ner,nec });

		}
	}
	
	nextq.push(swan[0]);
	d_visited[swan[0].row][swan[0].col] = 1;
	int mel_cnt = 0;

	while (!meet_flag) {
		
		bfs_ch(++mel_cnt);
		
		if (meet_flag) cout<< mel_cnt -1 ;
	}
	

	return 0;
}