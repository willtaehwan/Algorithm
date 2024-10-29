#include <iostream>
#define INF (int)1e9
using namespace std;

int N;
int dp[101][10][1024] = {0, };

int main() {

	cin >> N;

	for (int i = 1; i < 10; i++) dp[0][i][1 << i] = 1;

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 1024; k++) {
				if (j > 0) dp[i][j][k | (1 << j)] += dp[i - 1][j - 1][k];
				if (j < 9) dp[i][j][k | (1 << j)] += dp[i - 1][j + 1][k];
				dp[i][j][k | (1 << j)] %= INF;
			}
		}
	}

	int result = 0;
	for (int i = 0; i < 10; i++) result = (result + dp[N-1][i][1023]) % INF;
	cout << result;
	return 0;
}