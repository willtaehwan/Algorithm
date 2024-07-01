#include <iostream>
#include <algorithm>
using namespace std;

/*
row = 물건의 index
col = 무게

*/

struct item {
	int w;
	int v;
};

int N, K;

item arr[101];

int DP[101][100010] = { 0, };

int main() {

	cin >> N >> K;


	for (int i = 1; i <= N; i++) cin >> arr[i].w >> arr[i].v;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j - arr[i].w >= 0) DP[i][j] = max(DP[i - 1][j - arr[i].w] + arr[i].v, DP[i-1][j]);
			else DP[i][j] = DP[i - 1][j];
			
		}
	}

	cout << DP[N][K];

	return 0;
}