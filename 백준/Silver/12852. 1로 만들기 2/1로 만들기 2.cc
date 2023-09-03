#include <iostream>

using namespace std;

int DP[1000001] = { 0, };
int DP2[1000001] = { 0, };

void func(int now) {

	if (now <= 1) {
		return;
	}

	cout << DP2[now]<<" ";
	func(DP2[now]);
}

int main() {

	int N;
	cin >> N;

	DP[1] = 0; DP2[1] = 0;
	DP[2] = 1; DP2[2] = 1;
	DP[3] = 1; DP2[3] = 1;
	for (int i = 4; i <= N; i++) {
		DP[i] = DP[i - 1] + 1; DP2[i] = i - 1;
		if (i % 3 == 0) {
			if (DP[i / 3] + 1 < DP[i]) {
				DP[i] = DP[i / 3] + 1;
				DP2[i] = i / 3;
			}
			
		}
		if (i % 2 == 0) {
			if (DP[i / 2] + 1 < DP[i]) {
				DP[i] = DP[i / 2] + 1;
				DP2[i] = i / 2;
			}
		}

	}
	cout << DP[N] << endl;
	cout << N << " ";
	func(N);

	return 0;
}