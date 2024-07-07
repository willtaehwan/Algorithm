#include <iostream>
#define ull unsigned long long
using namespace std;

ull N, K;
int M;

int inverse(int b, int m) {

	if (m == 0) return 1;

	int temp = inverse(b, m / 2) % M;
	if (m % 2 == 0) return (temp * temp) % M;
	else return (((temp * temp) % M) * (b % M)) % M;
}

int binom(int n, int k) {
	
	if (n < k) return 0;
	if (k == 0 || n == k) return 1;
	if (k == 1 || n == 1) return n;

	if (n - k < k) k = n - k;

	int A = 1, B = 1;
	
	for (int i = n; i >= n - k + 1; i--) A = (A * i) % M;
	for (int i = 1; i <= k; i++) B = (B * i) % M;
	
	return (A * inverse(B, M - 2)) % M;
}

int main() {

	cin >> N >> K >> M;
	int result = 1;

	while (N > 0 || K > 0) {
		result = (result * binom(N % M, K % M)) % M;
		N /= M;
		K /= M;
	}

	cout << result;
	
	return 0;
}