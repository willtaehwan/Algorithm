#include <iostream>

using namespace std;

int N;

int DP[12] = { 0, };


int main() {

	int T;
	cin >> T;

	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 4;
	for (int i = 4; i <= 10; i++) {
		DP[i] = DP[i - 3] + DP[i - 2] + DP[i - 1];
	}
	
	for (int tc = 1; tc <= T; tc++) {

		cin >> N;
		cout <<DP[N]<<endl;
	}
	return 0;
}