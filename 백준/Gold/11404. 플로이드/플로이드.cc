#include <iostream>
#include <algorithm>
#define INF 10000000 
using namespace std;

int N, M;

int chart[105][105] = {0, };

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	cin >> M;

	for (int i = 1; i <=N; i++) {
		for (int j = 1; j <=N; j++) {
			if (i == j) continue;
			chart[i][j] = INF;
		}
	}

	for (int i = 0; i < M; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		if (chart[a][b] > cost) chart[a][b] = cost;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				chart[i][j] = min(chart[i][j], chart[i][k] + chart[k][j]);
			}
		}
	}
	
	for (int i = 1; i <=N; i++) {
		for (int j = 1; j <=N; j++) {
			if (chart[i][j] == INF) cout << "0 ";
			else cout << chart[i][j]<<" ";
		}
		cout << '\n';
	}
	

	return 0;
}