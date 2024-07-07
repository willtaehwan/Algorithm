#include <iostream>
#define ull unsigned long long
using namespace std;

/*
뤼카의 정리
1. N과 K를 M진수로 변환
2. 변환되어 생성된 N과 K의 계수 배열은 같은 index끼리 이항 계수를 구함 0<= 계수 < M 
3. 이 이항 계수는 M 이하의 자연수이고, M은 소수이기 때문에 두 수는 서로소임이 보장됨
4. 따라서, 페르마 소정리로 풀면 됨

*/

ull N, K;
int M;
int cnt = 0;
int arr_N[201];
int arr_K[201];
int MOD[201];

void baseM() {

	ull temp_N = N;
	ull temp_K = K;

	while (temp_N > 0 || temp_K > 0) {
		arr_N[cnt] = temp_N % M;
		arr_K[cnt] = temp_K % M;
		temp_N /= M;
		temp_K /= M;
		// cout << arr_N[cnt] << " " << arr_K[cnt] << '\n';
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

	int A = 1;
	int B = 1;
	
	
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