#include <iostream>
#include <cstring>
using namespace std;

int N;
int map[2][100001] = { 0, };
int DP[2][100001] = { 0, };

void init() {

	memset(map, 0, sizeof(map));
	memset(DP, 0, sizeof(DP));
}

void input() {



	cin >> N;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}


}


int solution() {

	DP[0][0] = map[0][0];
	DP[1][0] = map[1][0];
	DP[0][1] = DP[1][0] + map[0][1];
	DP[1][1] = DP[0][0] + map[1][1];

	for (int i = 2; i < N; i++) {
		for (int j = 0; j < 2; j++) {
			int num = j;
			int num2 = (j+1) % 2;
			if (DP[num2][i - 2] <= DP[num2][i - 1]) {
				DP[num][i] = DP[num2][i - 1] + map[num][i];
			}
			else {
				DP[num][i] = DP[num2][i - 2] + map[num][i];
			}
		}

	}

	int maxNum = max(DP[0][N-1], DP[1][N-1]);
	return maxNum;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {

		init();
		input();
		cout<<solution()<<endl;

	}

	return 0;
}