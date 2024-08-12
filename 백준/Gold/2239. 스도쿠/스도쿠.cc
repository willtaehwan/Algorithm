#include <iostream>

using namespace std;

bool row[10][10] = { 0, };
bool col[10][10] = { 0, };
bool sq[10][10] = { 0, };

int map[10][10];

int sqn(int i, int j) {
	return ((i / 3) * 3) + (j / 3);
}
void rec(int idx) {

	if (idx == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << map[i][j];
			}
			cout << '\n';
		}
		exit(0);
		return;
	}
	int i = idx / 9;
	int j = idx % 9;
	if (map[i][j] == 0) {
		for (int k = 1; k <= 9; k++) {
			if (row[i][k] || col[j][k] || sq[sqn(i,j)][k]) continue;
			row[i][k] = 1;
			col[j][k] = 1;
			sq[sqn(i, j)][k] = 1;
			map[i][j] = k;
			rec(idx + 1);
			map[i][j] = 0;
			row[i][k] = 0;
			col[j][k] = 0;
			sq[sqn(i, j)][k] = 0;
		}
	}
	else rec(idx + 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 9; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < 9; j++) {
			map[i][j] = str[j] - '0';
			row[i][map[i][j]] = 1;
			col[j][map[i][j]] = 1;
			sq[sqn(i, j)][map[i][j]] = 1;
		}
	}

	rec(0);

	return 0;
}