#include <iostream>
#include <vector>

using namespace std;

int N, M, k;

struct dmap {
	int smell;
	int num;
};

dmap map[21][21] = { 0, };

struct Node {
	int row;
	int col;
	int dir;
};

struct shark {
	int sur;
	int row;
	int col;
	int dir;
	int nextdr[4][4];
};

shark Now[500] = { 0, };

int dr[] = { 0,-1,1,0,0 };
int dc[] = { 0,0,0,-1,1 };

Node sharkMove(int num) {

	shark nows = Now[num];

	for (int i = 0; i < 4; i++) {
		int ned = nows.nextdr[nows.dir - 1][i];
		int ner = nows.row + dr[ned];
		int nec = nows.col + dc[ned];

		if (ner < 0 || nec < 0 || ner >= N || nec >= N) continue;
		if (map[ner][nec].smell != 0) continue;


		Now[num].row = ner;
		Now[num].col = nec;
		Now[num].dir = nows.nextdr[nows.dir - 1][i];
		
		return { ner,nec,ned };
	}

	
	for (int i = 0; i < 4; i++) {
		int ned = nows.nextdr[nows.dir - 1][i];
		int ner = nows.row + dr[ned];
		int nec = nows.col + dc[ned];

		if (map[ner][nec].num != num) continue;
		
		Now[num].row = ner;
		Now[num].col = nec;
		Now[num].dir = nows.nextdr[nows.dir - 1][i];

		return { ner,nec,ned };

	}
}

int main() {

	cin >> N >> M >> k;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int state;
			cin >> state;
			map[i][j].num = state;
			if (state != 0) {
				map[i][j].smell = k;
				Now[state].sur = 1;
				Now[state].row = i;
				Now[state].col = j;
 			}
		}
	}

	for (int i = 1; i <= M; i++) {
		int dir;
		cin >> dir;
		Now[i].dir = dir;
	}

	for (int i = 1; i <= M; i++) {

		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				int at;
				cin >> at;
				Now[i].nextdr[j][k] = at;
			}
		}

	}

	int cnt = 0;
	while (cnt<1001) {

		int checkMap[21][21] = { 0, };
		
		for (int i = M; i >= 1; i--) {
			if (Now[i].sur == 0) continue;

			Node ans = sharkMove(i);
			int checkNum = checkMap[ans.row][ans.col];

			if (checkNum != 0) {
				Now[checkNum].sur = 0;
			}
			
			checkMap[ans.row][ans.col] = i;
			
		}
		

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j].smell != 0) map[i][j].smell--;
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (checkMap[i][j] != 0) {
					map[i][j].num = checkMap[i][j];
					map[i][j].smell = k;
					
				}
			}

		}

		cnt++;

		int sl = 0;
		for (int i = 2; i <= M; i++) {
			if (Now[i].sur != 0) {
				sl++;
				break;
			}
		}

		if (sl == 0) break;

	}

	if (cnt == 1001) cout << -1;
	else cout << cnt;

	return 0;
}