#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N;

int map[21][21] = { 0, };
int checkedMap[21][21] = { 0, };
int chmap[21][21] = { 0, };
int dirCnt[4] = { 1,0,0,-1 };
int dr[] = { 1,1,-1,-1 };
int dc[] = { -1,1,1,-1 };

struct Node {
	int row;
	int col;
};

struct lim {
	int xst;
	int xen;
	int yst;
	int yen;
};

int minResult = 99999;

void bfs(int row, int col, lim l1, int num) {

	queue<Node> q;
	q.push({ row,col });
	chmap[row][col] = num;
	while (!q.empty()) {
		Node now = q.front(); q.pop();

		int dr[] = { -1,1,0,0 };
		int dc[] = { 0,0,-1,1 };
		for (int i = 0; i < 4; i++) {
			int ner = now.row + dr[i];
			int nec = now.col + dc[i];

			if (ner < l1.xst || nec < l1.yst || ner >= l1.xen || nec >= l1.yen) continue;

			if (chmap[ner][nec] != 0) continue;

			chmap[ner][nec] = num;

			q.push({ ner,nec });

		}

	}

	return;
}

void ccheck(int str, int stc) {

	for (int i = 0; i < N; i++) {
		for(int j = 0; j<N;j++){
			if (checkedMap[i][j] == 5) chmap[i][j] = 5;
			else chmap[i][j] = 0;
		}
	}

	lim l1 = { 0,str + dirCnt[0], 0, stc+1};
	lim l2 = { 0,str + dirCnt[3]+1, stc + 1, N };
	lim l3 = { str + dirCnt[0], N, 0, stc - dirCnt[0] + dirCnt[1]};
	lim l4 = { str + dirCnt[3] + 1, N, stc - dirCnt[0] + dirCnt[1],N };
	// 0 ~ str + d0 / 0 ~ stc
	// 0 ~ str + d3 / stc+1 ~ N-1
	// str + d0 + 1 ~ N -1 / 0 ~ stc - d0 + d1 - 1
	// str + d3 ~ N - 1 / stc - d0 + d1 ~ N - 1
	
	bfs(str, stc-1, l1, 1);
	bfs(str, stc+1, l2, 2);
	bfs(str + dirCnt[0] + dirCnt[1], stc - dirCnt[0] + dirCnt[1] - 1, l3, 3);
	bfs(str + dirCnt[0] + dirCnt[1], stc - dirCnt[0] + dirCnt[1] + 1, l4, 4);

	int ans[5] = { 0, };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (chmap[i][j] == 1) ans[0] += map[i][j];
			else if (chmap[i][j] == 2) ans[1] += map[i][j];
			else if (chmap[i][j] == 3) ans[2] += map[i][j];
			else if (chmap[i][j] == 4) ans[3] += map[i][j];
			else ans[4] += map[i][j];
		}
	}
	
	sort(ans, ans + 5);

	minResult = min(minResult, ans[4] - ans[0]);

	return;
}


void check(int row, int col, int dir, int str, int stc) {

	if (str==row && stc == col && dir==3) {
		ccheck(str,stc);

		return;
	}

	if (str >= row && col != stc) {
		return;
	}

	for (int i = dir; i <= dir+1; i++) {
		if (dir >= 4) continue;
		int ner = row + dr[dir];
		int nec = col + dc[dir];
		int ned = i;

		if (ner < 0 || nec < 0 || ner >= N || nec >= N) continue;
		
		if (checkedMap[ner][nec] != 0) continue;

		checkedMap[ner][nec] = 5;
		//cout << ner <<" " << nec << " "<<ned<<endl;
		dirCnt[ned]++;
		check(ner, nec, ned, str, stc);
		dirCnt[ned]--;
		checkedMap[ner][nec] = 0;

	}

	
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	//cout << endl;
	for (int i = 0; i < N-2; i++) {
		for (int j = 1; j < N-1; j++) {
			/*cout << "=====================" << endl;
			cout << i << " "<<j << endl;
			cout << "========   " << endl;*/
			
			check(i,j,0,i,j);
		}
	}

	cout << minResult;

	return 0;
}