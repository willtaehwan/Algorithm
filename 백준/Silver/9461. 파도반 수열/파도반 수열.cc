#include <iostream>
using namespace std;
int N;
long long int DP[101] = { 0, };
int main() {
	int T;
	cin >> T;
	DP[1] = 1; DP[2] = 1; DP[3] = 1; DP[4] = 2; DP[5] = 2;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		for (int i = 6; i <= N; i++) {
			DP[i] = DP[i - 1] + DP[i - 5];
		}
		cout << DP[N]<<endl;
	}
	return 0;
}