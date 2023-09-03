#include <iostream>

using namespace std;

long long int DPa[100] = { 0, };
long long int DPb[100] = { 0, };

int main() {

	int N;

	cin >> N;

	DPa[1] = 1; DPb[1] = 0;
	DPa[2] = 1; DPb[2] = 0;
	
	for (int i = 3; i <= N; i++) {
		DPa[i] = DPa[i - 1] + DPb[i - 1];
		DPb[i] = DPa[i - 1];
	}
	
	cout << DPa[N] + DPb[N];

	return 0;
}