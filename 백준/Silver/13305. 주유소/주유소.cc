#include <iostream>

using namespace std;

int N;

int cost[100001];
int dist[100001];

int main() {

	cin >> N;

	for (int i = 0; i < N - 1; i++) cin >> dist[i];
	
	int tot_cost = 0;
	int min_cost = 1e9;
	for (int i = 0; i < N; i++) {
		cin >> cost[i];
		if (min_cost > cost[i]) min_cost = cost[i];
		tot_cost += min_cost * dist[i];
	}
	cout << tot_cost;

	return 0;
}