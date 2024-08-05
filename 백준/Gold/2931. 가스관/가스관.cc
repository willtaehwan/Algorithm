#include <iostream>

using namespace std;

struct Node {
	int row;
	int col;
	int dir;
};

char map[26][26];

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

int R, C;

Node Z;

bool chart[4][7] = {
	{1,0,0,1,1,0,1},
	{0,1,1,0,1,0,1},
	{1,1,0,0,0,1,1},
	{0,0,1,1,0,1,1}
};

int check[4][7] = {
	{ 3,-1,-1, 2, 0,-1, 0},
	{-1, 3, 2,-1, 1,-1, 1},
	{ 1, 0,-1,-1,-1, 2, 2},
	{-1,-1, 0, 1,-1, 3, 3}
};

char chch[16];

void search_block(Node node) {

	// + : 4방이 다 오픈
	// -, | : 들어온 방향의 반대 방향 오픈
	// 1 : 
	int result = 1;
	for (int i = 0; i < 4; i++) {
		result = result << 1;

		int ner = node.row + dr[i];
		int nec = node.col + dc[i];
		if (ner < 0 || nec < 0 || ner >= R || nec >= C) continue;
		if (map[ner][nec] == '.' || map[ner][nec] == 'M' || map[ner][nec] == 'Z') continue;

		int next = map[ner][nec] - '1';
		if (chart[i][next]) result += 1;

	}
	result -= 16;
	if (result == 15) cout << "+";
	else cout << chch[result];

}

void dfs(Node node) {

	char now = map[node.row][node.col];
	int now2 = now - '1';
	int ned = check[node.dir][now2];

	if (now == '.') {
		cout << node.row + 1 << " " << node.col + 1 << ' ';
		search_block(node);
		return;
	}

	dfs({ node.row + dr[ned], node.col + dc[ned], ned });

}

int main() {

	chch[5] = '1'; chch[9] = '2'; chch[10] = '3'; chch[6] = '4';
	chch[3] = '-'; chch[12] = '|';

	cin >> R >> C;
	Node start = { 0,0,0 };
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'M') start = { i,j,-1 };
			if (map[i][j] == 'Z') Z = { i,j,-1 };
			if (map[i][j] == '|') map[i][j] = '5';
			if (map[i][j] == '-') map[i][j] = '6';
			if (map[i][j] == '+') map[i][j] = '7';
		}
	}

	for (int i = 0; i < 4; i++) {
		int ner = start.row + dr[i];
		int nec = start.col + dc[i];
		if (ner < 0 || nec < 0 || ner >= R || nec >= C) continue;
		if (map[ner][nec] == '.' || map[ner][nec] == 'Z') continue;
		int next = map[ner][nec] - '1';

		if (!chart[i][next]) continue;

		start = { ner,nec,i };
		break;
	}

	dfs(start);


	return 0;
}