#include <iostream>
#define INF 10000
using namespace std;

int N, M;

int DP[21][21][21] = { 0, };
int arr[21] = { 0, };
int main() {

	cin >> N;
	int a, b;
	cin >> a >> b;
	cin >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k <= M; k++) {
				DP[i][j][k] = INF;
			}
		}
	}
	
	DP[a][b][0] = 0;

	for (int i = 1; i <= M; i++) cin >> arr[i];
	int min_result = INF;
	for (int k = 1; k <= M; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (DP[i][j][k-1] == INF) continue;
				int tar = arr[k];
				DP[tar][i][k] = min(DP[tar][i][k], DP[i][j][k - 1] + abs(j - tar));
				DP[tar][j][k] = min(DP[tar][j][k], DP[i][j][k - 1] + abs(i - tar));
				
			}
		}
	}

	for (int i = 1; i <= N; i++) min_result = min(min_result, DP[arr[M]][i][M]);
	cout << min_result;

	return 0;
}