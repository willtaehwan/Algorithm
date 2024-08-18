#include<iostream>
#include <algorithm>
#define INF 1e9
using namespace std;

int N;

int map[16][16];
int dp[16][65536];

bool st_check(int next, int stat) {
	if (stat & (1 << next)) return true;
	return false;
}

int tsp(int now, int status) {

	if (status == ((1 << N) - 1)) {
		if (map[now][0] == 0) return INF;
		return map[now][0];
	}

	if (dp[now][status] != -1) return dp[now][status];

	dp[now][status] = INF;
	for (int i = 0; i < N; i++) {
		if (!map[now][i]) continue;
		if (st_check(i, status)) continue;

		dp[now][status] = min(dp[now][status], tsp(i, (status | 1 << i)) + map[now][i]);
	}
	return dp[now][status];

}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) fill_n(dp[i], size(dp[i]), -1);

	cout << tsp(0, 1);

	return 0;
}