#include <iostream>
#include <cstring>
using namespace std;

int N;
int map[1001][3] = { 0, };
int DP[1001][3] = {0,};

int func(int now, int row) {

	if (row > N) {
		return 0;
	}

	if (DP[row][now] != 0) {
		return DP[row][now];
	}

	int bestC = 21345678;
	for (int i = 0; i < 3; i++) {
		int next = i;
		int nextRow = row + 1;
		if (next == now) {
			continue;
		}

		int nextScore = func(next,nextRow);

		bestC = min(bestC, nextScore);
	}

	int nowScore = bestC + map[row][now];
	DP[row][now] = nowScore;
	return nowScore;
}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> map[i][j];
		}
	}
	int min_rate = 1e9;
	for (int i = 0; i < 3; i++) {
		func(i,0);
		if (min_rate > DP[0][i]) {
			min_rate = DP[0][i];
		}
		memset(DP, 0, sizeof(DP));
	}
	
	cout << min_rate;

	return 0;
}