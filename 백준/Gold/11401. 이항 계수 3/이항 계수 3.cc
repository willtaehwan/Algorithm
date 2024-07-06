#include <iostream>
#define MOD 1000000007
#define ll unsigned long long

using namespace std;

int N, K;

ll expr(ll a, ll m) {
	
	a %= MOD;
	ll temp = 1;

	while (m > 0) {
		if (m % 2 == 1) {
			temp *= a;
			temp %= MOD;
		}

		a *= a;
		a %= MOD;
		m /= 2;
	}

	return temp;
}

int main() {

	cin >> N >> K;

	if (K == 0 || K == N) {
		cout << 1;
		return 0;
	}

	if (K == 1 || N == 1) {
		cout << N;
		return 0;
	}

	if (K > N / 2) K = N - K;

	ll A = 1, B = 1, result;

	for (int i = N; i >= N - K + 1; i--) A = (A * i) % MOD;

	for (int i = 1; i <=K; i++) B = (B * i) % MOD;

	result = ((A % MOD) * (expr(B, MOD - 2) % MOD)) % MOD;
	
	cout << result;

	return 0;
}