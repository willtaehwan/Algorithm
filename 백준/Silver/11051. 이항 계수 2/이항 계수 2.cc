#include <iostream>
#define MOD 10007;
using namespace std;

int N, K;

int DP[1001] = { 0, };

int main() {

	cin >> N >> K;

	for (int i = 0; i <=N; i++) {
		DP[i] = 1;
		for (int j = i-1; j >0; j--) {
			DP[j] = (DP[j - 1] + DP[j]) % MOD;
		}
	}

	cout << DP[K];

	return 0;
}