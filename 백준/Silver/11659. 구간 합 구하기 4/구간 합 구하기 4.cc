#include <iostream>

using namespace std;

int DP[100001] = { 0, };
int map[100001] = { 0, };
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N,M;

	cin >> N>>M;
	
	for (int i = 1; i <= N; i++) {
		cin >> map[i];
		DP[i] = DP[i - 1] + map[i];
	}


	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cout << DP[b] - DP[a - 1]<<"\n";
	}
	

	return 0;
}