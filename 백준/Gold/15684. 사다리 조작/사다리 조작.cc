#include <iostream>
#include <vector>

using namespace std;

int N, M, H;

int map[31][11] = { 0, };

struct Node {
	int row;
	int col;
};

vector<Node> v;

int result = -1;

int sdr_result = 0;

void sdr(int row, int col, int num) {

	if (row == H) {
		if (col != num) sdr_result = 1;
		return;
	}

	sdr(row + 1, col + map[row][col], num);



}

bool sdr_check() {

	int flag = 0;

	for (int i = 0; i < N; i++) {
		sdr_result = 0;
		sdr(0, i, i);
		if (sdr_result == 1) {
			flag = 1;
			break;
		}
	}

	if (flag == 1) return 0;
	else return 1;
}


void dfs(int now, int num, int prev) {

	if (now == num) {
		if (sdr_check()) result = num;
		return;
	}

	for (int i = prev; i < v.size(); i++) {
		int ner = v[i].row;
		int nec = v[i].col;

		if (map[ner][nec] != 0) continue;

		map[ner][nec] = 1;
		map[ner][nec + 1] = -1;
		dfs(now + 1, num, i+1);
		map[ner][nec] = 0;
		map[ner][nec + 1] = 0;

	}

}

int main() {

	cin >> N >> M >> H;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		map[a - 1][b - 1] = 1;
		map[a - 1][b] = -1;
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N-1; j++) {
			if (map[i][j] == 0 && map[i][j+1] == 0) v.push_back({i,j});
		}
	}

	if (sdr_check()) result = 0;

	for (int i = 1; i < 4; i++) {
		if (result != -1) break;
		dfs(0, i, 0);
	}
	
	cout << result;

	return 0;
}