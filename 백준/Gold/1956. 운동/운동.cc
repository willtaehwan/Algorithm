#include <iostream>
#include <algorithm>
#define INF 1e9
using namespace std;

int map[402][402] = { 0, };

int V, E;

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> V >> E;

	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			if (i == j) continue;
			map[i][j] = INF;
		}
	}

	for (int i = 0; i < E; i++) {
		int s, e, c;
		cin >> s >> e >> c;
		map[s][e] = c;
	}

	for (int k = 1; k <= V; k++) {
		for (int i = 1; i <= V; i++) {
			if (i == k) continue;
			for (int j = 1; j <= V; j++) {
				if (j == i || j == k) continue;
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
			}
		}
	}

	int min_result = INF;

	for (int i = 1; i <= V; i++) {
		for (int j = i+1; j <= V; j++) {
			min_result = min(min_result, map[i][j] + map[j][i]);
		}
	}

	if (min_result == INF) cout << -1;
	else cout << min_result;


	return 0;
}