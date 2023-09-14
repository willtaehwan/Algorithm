#include <iostream>
#include <algorithm>
using namespace std;

int N;

int A[51] = { 0, };
int B[51] = { 0, };

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}

	sort(A, A + N);
	sort(B, B + N);
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += A[i] * B[N-1 - i];
	}
	cout << sum;

	return 0;
}