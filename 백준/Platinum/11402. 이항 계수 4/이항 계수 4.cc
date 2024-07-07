#include <iostream>
#define ull unsigned long long
using namespace std;

ull N, K;
int M;
int cnt = 0;
int arr_N[40];
int arr_K[40];
int MOD[40];

void baseM() {

	ull temp_N = N;
	ull temp_K = K;

	while (temp_N > 0 || temp_K > 0) {
		arr_N[cnt] = temp_N % M;
		arr_K[cnt] = temp_K % M;
		temp_N /= M;
		temp_K /= M;
		cnt++;
	}
}

int inverse(int b, int m) {

	if (m == 0) return 1;

	int temp = inverse(b, m / 2) % M;
	if (m % 2 == 0) return (temp * temp) % M;
	else return (((temp * temp) % M) * (b % M)) % M;
}

void binom(int n, int k, int idx) {
	
	if (n < k) {
		MOD[idx] = 0;
		return;
	}

	if (k == 0 || n == k) {
		MOD[idx] = 1;
		return;
	}

	if (k == 1 || n == 1) {
		MOD[idx] = n;
		return;
	}

	if (n - k < k) k = n - k;

	int A = 1, B = 1;
	
	for (int i = n; i >= n - k + 1; i--) A = (A * i) % M;
	for (int i = 1; i <= k; i++) B = (B * i) % M;
	
	MOD[idx] = ((A%M) * (inverse(B, M-2)%M)) % M;
}

int main() {

	cin >> N >> K >> M;

	baseM();
	
	for (int i = 0; i < cnt; i++) binom(arr_N[i], arr_K[i], i);

	int result = 1;

	for (int i = 0; i < cnt; i++) result = (result * MOD[i]) % M;

	cout << result;
	
	return 0;
}