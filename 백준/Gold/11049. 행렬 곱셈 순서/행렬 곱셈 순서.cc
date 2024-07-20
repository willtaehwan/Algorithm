#include <iostream>
#include <algorithm>
using namespace std;

int N;

int arr[505];
int dp[505][505] = { 0, };

int main() {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int f, b;
		cin >> f >> b;
		arr[i] = f;
		if (i == N) arr[i + 1] = b;
	}

	for (int n = 1; n <= N-1; n++) { // (1, 2) ~ (1, N)까지 / 범위를 나타내기도 함
		int i = 1; // 시작하는 row는 항상 1
		int j = n+1; // 시작하는 col은 1씩 증가
		for (int k = 0; k < N - n; k++) { //(1, n) 부터 (1+k, n+k)까지 n이 1씩 증가 할 때 마다 총 길이가 1씩 감소함, 처음에는 N-1회
			dp[i][j] = 1e9;
			
			for (int m = 0; m < n; m++) {
				dp[i][j] = min(dp[i][j], dp[i][i+m] + dp[i+m+1][j] + arr[i] * arr[j+1] * arr[i+m+1]);
			}
			
			i++;
			j++;
		}

	}

	cout << dp[1][N];

	return 0;
}