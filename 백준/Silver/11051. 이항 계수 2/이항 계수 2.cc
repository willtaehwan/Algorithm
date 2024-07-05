#include <iostream>
#define MOD 10007;
using namespace std;

int N, K;

int DP[1001][1001] = { 0, };

int ft(int a, int b) {
	
	if (a == b || b == 0) return 1;

	if (DP[a][b] != 0) return DP[a][b];

	DP[a][b] = (ft(a - 1, b - 1) + ft(a - 1, b)) % MOD;

	return DP[a][b];
}

int main() {

	cin >> N >> K;
	
	cout << ft(N, K);


	return 0;
}