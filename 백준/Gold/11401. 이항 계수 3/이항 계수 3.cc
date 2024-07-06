#include <iostream>
#define MOD 1000000007
using namespace std;

int N, K;

long long temp;

long long expr(long long a, long long m) {
	
	if (m == 0) return 1;

	temp = expr(a, m / 2) % MOD;
	if (m % 2 == 0) return temp * temp % MOD;
	else return temp * temp % MOD * a % MOD ;
}

int main() {

	cin >> N >> K;

	long long A = 1, B = 1, result;

	for (int i = N; i >= N - K + 1; i--) A = (A * i) % MOD;

	for (int i = 1; i <=K; i++) B = (B * i) % MOD;

	result = ((A % MOD) * (expr(B, MOD - 2) % MOD)) % MOD;
	
	cout << result;

	return 0;
}