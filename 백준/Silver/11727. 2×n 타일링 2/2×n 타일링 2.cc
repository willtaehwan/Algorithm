#include <iostream>

using namespace std;

int DPa[1001] = { 0, };
int DPb[1001] = { 0, };

int main() {

	int N;

	cin >> N;

	DPa[1] = 1;
	DPa[2] = 1; DPb[2] = 2;
	

	for (int i = 3; i <= N; i++) {
		DPa[i] = (DPa[i - 1] + DPb[i - 1])%10007;
		DPb[i] = (DPa[i - 1] * 2)%10007;
	}

	cout << (DPa[N] + DPb[N])%10007;

	return 0;
}