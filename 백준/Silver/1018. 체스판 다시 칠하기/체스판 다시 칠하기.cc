#include <iostream>

using namespace std;

int map[51][51] = { 0, };

int checkMap1[8][8] = {
	{0,1,0,1,0,1,0,1},
	{1,0,1,0,1,0,1,0},
	{0,1,0,1,0,1,0,1},
	{1,0,1,0,1,0,1,0},
	{0,1,0,1,0,1,0,1},
	{1,0,1,0,1,0,1,0},
	{0,1,0,1,0,1,0,1},
	{1,0,1,0,1,0,1,0}
};

int checkMap2[8][8] = {
	{1,0,1,0,1,0,1,0},
	{0,1,0,1,0,1,0,1},
	{1,0,1,0,1,0,1,0},
	{0,1,0,1,0,1,0,1},
	{1,0,1,0,1,0,1,0},
	{0,1,0,1,0,1,0,1},
	{1,0,1,0,1,0,1,0},
	{0,1,0,1,0,1,0,1}
};

int check(int row, int col) {

	int cnt1 = 0;
	int cnt2 = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (map[row + i][col + j] != checkMap1[i][j]) {
				cnt1++;
			}
			if (map[row + i][col + j] != checkMap2[i][j]) {
				cnt2++;
			}
		}
	}

	if (cnt1 < cnt2) {
		return cnt1;
	}
	else {
		return cnt2;
	}

}

int main(){

	int N, M;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string row;
		cin >> row;
		for (int j = 0; j < M; j++) {
			if (row[j] == 'W') {
				map[i][j] = 0;
			}
			else {
				map[i][j] = 1;
			}
		}
	}


	int min_result = 1e9;
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			int ans = check(i, j);
			if (ans < min_result) {
				min_result = ans;
			}
		}
	}

	cout << min_result;

	return 0;
}