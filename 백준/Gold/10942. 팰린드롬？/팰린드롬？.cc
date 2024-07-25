#include <iostream>

using namespace std;

int N, M;

int arr[2010];

bool dp[2010][2010] = {0,};

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		dp[i][i] = 1;
		if (arr[i - 1] == arr[i]) dp[i - 1][i] = 1;
	}

	for (int i = 2; i <= N - 1; i++) {
		for (int j = 1; i + j <= N; j++) {
			if (arr[j] == arr[i + j] && dp[j + 1][i + j - 1] == 1) dp[j][i + j] = 1;
		}
	}
	
	cin >> M;

	for (int i = 0; i < M; i++) {
		int S, E;
		cin >> S >> E;
		cout << dp[S][E]<<'\n';
	}


	return 0;
}