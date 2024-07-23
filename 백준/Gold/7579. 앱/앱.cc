#include <iostream>
#include <algorithm>
using namespace std;

int N, M;

int DP[102][10010] = { 0, };

int mem[102] = { 0, };
int cost[102] = { 0, };

int main() {

	cin >> N >> M;
	int full_cost = 0;
	for (int i = 1; i <= N; i++) cin >> mem[i];
	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
		full_cost += cost[i];
	}
	int min_cost = 1e9;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= full_cost; j++) {
			if (min_cost < j) break;

			if (j - cost[i] >= 0) DP[i][j] = max(DP[i - 1][j - cost[i]] + mem[i], DP[i - 1][j]);
			else DP[i][j] = DP[i - 1][j];

			if (DP[i][j] >= M) {
				min_cost = min(min_cost, j);
			}

		}
	}
	/*
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= full_cost; j++) {
			cout << DP[i][j]<<"\t";
		}
		cout << '\n';
	}
	*/
	cout << min_cost;

	return 0;
}