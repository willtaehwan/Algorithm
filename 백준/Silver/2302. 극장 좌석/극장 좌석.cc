#include <iostream>

using namespace std;

int DP[41] = { 0, };
bool arr[41] = { 0, };
int N, M;

int main() {

	cin >> N >> M;

	DP[1] = 1;
	DP[2] = 2;
	for (int i = 3; i <= N; i++) {
		DP[i] = DP[i - 1] + DP[i - 2];
		//cout << i<<" : "<<DP[i] << '\n';
	}

	for (int i = 0; i < M; i++) {
		int no;
		cin >> no;
		arr[no] = 1;
	}
	int cnt = 0;
	int result = 1;
	for(int i = 1; i<=N+1;i++){
		if (arr[i] || i == N+1) {
			if(cnt) result *= DP[cnt];
			cnt = 0;
		}
		else cnt++;
	}

	cout << result;

	return 0;
}