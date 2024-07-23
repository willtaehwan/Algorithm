#include <iostream>
#include <algorithm>
using namespace std;

int N, M;

int DP[10010] = { 0, };

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
	
	for (int i = 1; i <= N; i++) {
		for (int j = full_cost; j >=0; j--) {
			if (j - cost[i] >= 0) DP[j] = max(DP[j - cost[i]] + mem[i], DP[j]);

			if (DP[j] >= M) full_cost = min(full_cost, j);
		}
	}
	
	cout << full_cost;

	return 0;
}