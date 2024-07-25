#include <iostream>

using namespace std;

int N, M;

int arr[2001];

bool dp[2001][2][1010] = {0,};

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) cin >> arr[i];

	for (int i = 1; i <= N; i++) {
		
		for (int k = 0; k < 2; k++) {
			bool flag = true;
			
			for (int j = 0; j <= N / 2; j++) {
				int left = i - j;
				int right = i + j;
				if (k == 1) right = i+j+1;
				if (left<0 || right>N) break;
				if (arr[left] != arr[right]) flag = false;
				if (!flag) break;
				dp[i][k][j] = flag;
			}
		}
	}
	/*
	cout << '\n';
	for (int i = 0; i <= N; i++) {
		for (int k = 0;k < 2; k++) {
			cout << "   ";
			for (int j = 0; j <= N / 2; j++) {
				cout << dp[i][k][j] << " ";
			}
		}
		cout << '\n';
	}
	*/
	cin >> M;

	for (int i = 0; i < M; i++) {
		int S, E;
		cin >> S >> E;
		int m = (E + S) / 2;
		int l = m - S;
		int k = 0;
		if ((E + S) % 2 == 1) k = 1;
		cout << dp[m][k][l]<<'\n';
	}


	return 0;
}